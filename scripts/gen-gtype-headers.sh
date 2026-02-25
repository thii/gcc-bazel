#!/bin/bash
# Regenerate pre-committed gengtype headers (rules/gengtype-output/).
#
# GCC's gengtype tool scans source files for GTY(...) annotations and
# generates gt-*.h / gtype-*.h headers that the garbage collector needs.
# These are checked in rather than built by Bazel because gengtype
# requires a full configure + partial make to produce.
#
# This script uses GCC's own build system to run gengtype, then copies
# the output into rules/gengtype-output/ for the Bazel build to consume.
#
# Prerequisites:
#   - GCC source fetched: bazel fetch @gcc
#   - Packages: build-essential flex libgmp-dev libmpfr-dev libmpc-dev
#
# Usage (from repo root):
#   scripts/gen-gtype-headers.sh

set -euo pipefail

REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
OUTPUT_DIR="$REPO_ROOT/rules/gengtype-output"
BUILDDIR=/tmp/gcc-build

# Find GCC source in Bazel cache (output base hash varies per environment)
GCC_SRC=$(find "$REPO_ROOT/bazel-cache"/*/external/+gcc_ext+gcc -maxdepth 0 -type d 2>/dev/null | head -1)
if [ -z "$GCC_SRC" ]; then
    echo "ERROR: Could not find GCC source in bazel-cache/*/external/+gcc_ext+gcc"
    echo "Run 'bazel fetch @gcc' first."
    exit 1
fi
echo "Using GCC source: $GCC_SRC"

# Install build deps if missing
if ! dpkg -s libgmp-dev libmpfr-dev libmpc-dev >/dev/null 2>&1; then
    echo "=== Installing prerequisites ==="
    apt-get update -qq && apt-get install -y -qq --no-install-recommends \
        libgmp-dev libmpfr-dev libmpc-dev 2>&1 | tail -3
fi

mkdir -p "$BUILDDIR"
cd "$BUILDDIR"

# Configure GCC with the frontends whose gtype headers we need
echo "=== Configuring GCC ==="
"$GCC_SRC/configure" \
    --enable-languages=c,c++,lto \
    --disable-bootstrap \
    --disable-multilib \
    2>&1 | tail -3

# Build just enough for gengtype to run
echo "=== Building prerequisites ==="
make configure-gcc -j"$(nproc)" 2>&1 | tail -3
make all-build-libiberty -j"$(nproc)" 2>&1 | tail -3
make all-libiberty -j"$(nproc)" 2>&1 | tail -3

# Build gengtype and run it
cd "$BUILDDIR/gcc"

echo "=== Building gengtype ==="
make -j"$(nproc)" build/gengtype 2>&1 | tail -5

echo "=== Running gengtype ==="
make -j1 s-gtyp-input 2>&1 | tail -3
make -j1 s-gtype 2>&1 | tail -5

# Copy output into the repo
echo "=== Copying to $OUTPUT_DIR ==="
for f in gt-*.h gtype-*.h gtype-*.cc; do
    [ -f "$f" ] && cp "$f" "$OUTPUT_DIR/$f" && echo "  $f"
done

echo ""
echo "Done. Review changes with: git diff --stat rules/gengtype-output/"
