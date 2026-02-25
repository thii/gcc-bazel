# GCC Bazel Build

An attempt to build GCC from source using Bazel, targeting x86_64-linux-gnu.

Requires Bazel 9.0+ and a host C/C++ toolchain. Tested with GCC 15 on Ubuntu 25.04.

## Build

```sh
bazel build //:gcc_dist
```

Produces `bazel-bin/gcc-16.0.1-x86_64-linux-gnu.tar.gz`.

## 3-Stage Bootstrap

```sh
# Stage 1: system GCC builds GCC
bazel build //:gcc_dist
mkdir -p toolchain/stage1
tar xf bazel-bin/gcc-16.0.1-x86_64-linux-gnu.tar.gz -C toolchain/stage1

# Stage 2: stage 1 GCC builds GCC
bazel build --config=stage2 //:gcc_dist
mkdir -p toolchain/stage2
tar xf bazel-bin/gcc-16.0.1-x86_64-linux-gnu.tar.gz -C toolchain/stage2

# Stage 3: stage 2 GCC builds GCC
bazel build --config=stage3 //:gcc_dist
```

Stage 2 and stage 3 outputs should be bit-identical.
