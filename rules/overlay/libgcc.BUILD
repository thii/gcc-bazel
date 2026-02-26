load("@rules_cc//cc:defs.bzl", "cc_library", "cc_shared_library")
load("@rules_cc//cc:cc_static_library.bzl", "cc_static_library")

package(default_visibility = ["//visibility:public"])

# ============================================================================
# Common compiler flags for libgcc
# ============================================================================

_LIBGCC_COPTS = [
    "-O2",
    "-g0",
    "-DIN_GCC",
    "-DIN_LIBGCC2",
    "-DHAVE_CONFIG_H",
    "-fbuilding-libgcc",
    "-fno-stack-protector",
    "-fvisibility=hidden",
    "-DHIDE_EXPORTS",
    "-DLIBGCC2_UNITS_PER_WORD=8",
    # i386/i386.h uses C++ bool; make it available in C via stdbool.h
    "-include", "stdbool.h",
]

_LIBGCC_INCLUDES = [
    ".",
    "config",
    "config/i386",
    "../gcc",
    "../gcc/config/i386",
    "../gcc/config",
    "../include",
]

_LIBGCC_DEPS = [
    "//gcc:gcc_headers",
    "//gcc:generated_headers",
    "//:include",
    "@gcc_config//:gcc_config",
    "@gcc_config//:libgcc_config",
]

# ============================================================================
# Generated header: libgcc_tm.h
# ============================================================================

genrule(
    name = "gen_libgcc_tm_h",
    outs = ["libgcc_tm.h"],
    cmd = """cat > $@ << 'EOF'
#ifndef LIBGCC_TM_H
#define LIBGCC_TM_H
#include "i386/elf-lib.h"
#endif
EOF""",
)

# gthr-default.h (posix threads for x86_64-linux-gnu)
genrule(
    name = "gen_gthr_default",
    outs = ["gthr-default.h"],
    cmd = "echo '#include \"gthr-posix.h\"' > $@",
)

# unwind.h is a copy of unwind-generic.h (created by Makefile during build)
genrule(
    name = "gen_unwind_h",
    srcs = ["unwind-generic.h"],
    outs = ["unwind.h"],
    cmd = "cp $< $@",
)

# md-unwind-def.h: for x86_64-linux-gnu, uses default no-unwind.h (empty stub)
genrule(
    name = "gen_md_unwind_def",
    srcs = ["config/no-unwind.h"],
    outs = ["md-unwind-def.h"],
    cmd = "cp $< $@",
)

# md-unwind-support.h: for x86_64-linux-gnu, points to i386/linux-unwind.h
genrule(
    name = "gen_md_unwind_support",
    srcs = ["config/i386/linux-unwind.h"],
    outs = ["md-unwind-support.h"],
    cmd = "cp $< $@",
)

cc_library(
    name = "libgcc_tm",
    hdrs = [":gen_libgcc_tm_h", ":gen_gthr_default", ":gen_unwind_h", ":gen_md_unwind_def", ":gen_md_unwind_support"] + glob(["config/**/*.h"]),
    includes = [".", "config"],
)

# Unwind headers needed by libsupc++ (in libstdc++-v3)
cc_library(
    name = "unwind_headers",
    hdrs = [
        "unwind-pe.h",
        ":gen_unwind_h",
    ],
    includes = ["."],
)

# ============================================================================
# CRT objects (standalone .o files from crtstuff.c)
# ============================================================================

_CRT_COPTS = [
    "-O2",
    "-g0",
    "-DIN_GCC",
    "-DHAVE_CONFIG_H",
    "-include", "stdbool.h",
    "-finhibit-size-directive",
    "-fno-inline",
    "-fno-exceptions",
    "-fno-zero-initialized-in-bss",
    "-fno-toplevel-reorder",
    "-fno-tree-vectorize",
    "-fbuilding-libgcc",
    "-fno-stack-protector",
]

_CRT_DEPS = [
    "//gcc:gcc_headers",
    "//gcc:generated_headers",
    "//:include",
    "@gcc_config//:gcc_config",
    ":libgcc_tm",
]

# Generate thin wrapper .c files for each CRT variant.
# Each wrapper #defines the variant and #includes crtstuff.c.

_CRT_VARIANTS = [
    ("crtbegin", ["-DCRT_BEGIN"], []),
    ("crtend", ["-DCRT_END"], []),
    ("crtbeginS", ["-DCRT_BEGIN", "-DCRTSTUFFS_O"], ["-fPIC"]),
    ("crtendS", ["-DCRT_END", "-DCRTSTUFFS_O"], ["-fPIC"]),
    ("crtbeginT", ["-DCRT_BEGIN", "-DCRTSTUFFT_O"], []),
]

# Generate wrapper source + cc_library + genrule to extract .o for each CRT variant
[genrule(
    name = "gen_" + name + "_c",
    outs = [name + "_wrapper.c"],
    cmd = "printf '#include \"crtstuff.c\"\\n' > $@",
) for name, _, _ in _CRT_VARIANTS]

# Headers from libgcc/ needed by crtstuff.c
_CRT_TEXTUAL_HDRS = ["crtstuff.c"] + glob(["unwind*.h", "gthr*.h"])

[cc_library(
    name = "_" + name + "_lib",
    srcs = [":" + name + "_wrapper.c"],
    copts = _CRT_COPTS + defines + extra_flags,
    includes = _LIBGCC_INCLUDES,
    linkopts = ["-nostartfiles", "-nodefaultlibs"],
    textual_hdrs = _CRT_TEXTUAL_HDRS,
    deps = _CRT_DEPS,
) for name, defines, extra_flags in _CRT_VARIANTS]

# Extract .o from cc_library .a (cc_library produces .a + .so, we need bare .o)
[genrule(
    name = name,
    srcs = [":_" + name + "_lib"],
    outs = [name + ".o"],
    cmd = "A=$$(echo '$(SRCS)' | tr ' ' '\\n' | grep '\\.a$$') && TMP=$$(mktemp -d) && ar x $$A --output=$$TMP && cp $$TMP/*.o $@",
) for name, _, _ in _CRT_VARIANTS]

# x86_64 precision control and fast math CRT objects
_CRT_EXTRA = [
    ("crtprec32", "config/i386/crtprec.c", ["-D__PREC=32"]),
    ("crtprec64", "config/i386/crtprec.c", ["-D__PREC=64"]),
    ("crtprec80", "config/i386/crtprec.c", ["-D__PREC=80"]),
    ("crtfastmath", "config/i386/crtfastmath.c", []),
]

[genrule(
    name = "gen_" + name + "_c",
    outs = [name + "_wrapper.c"],
    cmd = "printf '#include \"" + src + "\"\\n' > $@",
) for name, src, _ in _CRT_EXTRA]

[cc_library(
    name = "_" + name + "_lib",
    srcs = [":" + name + "_wrapper.c"],
    copts = _CRT_COPTS + defines,
    includes = _LIBGCC_INCLUDES + ["config/i386"],
    textual_hdrs = [src],
    deps = _CRT_DEPS,
) for name, src, defines in _CRT_EXTRA]

[genrule(
    name = name,
    srcs = [":_" + name + "_lib"],
    outs = [name + ".o"],
    cmd = "A=$$(echo '$(SRCS)' | tr ' ' '\\n' | grep '\\.a$$') && TMP=$$(mktemp -d) && ar x $$A --output=$$TMP && cp $$TMP/*.o $@",
) for name, _, _ in _CRT_EXTRA]

# Filegroup collecting all CRT objects
filegroup(
    name = "crt_objects",
    srcs = [
        ":crtbegin",
        ":crtend",
        ":crtbeginS",
        ":crtendS",
        ":crtbeginT",
        ":crtprec32",
        ":crtprec64",
        ":crtprec80",
        ":crtfastmath",
    ],
)

# ============================================================================
# libgcc2 per-function objects
# ============================================================================

# Functions from libgcc2.c, each compiled with -DL_<name>
_LIBGCC2_FUNCS = [
    "_muldi3", "_negdi2", "_lshrdi3", "_ashldi3", "_ashrdi3", "_cmpdi2", "_ucmpdi2",
    "_clear_cache", "_trampoline", "_absvsi2", "_absvdi2", "_addvsi3",
    "_addvdi3", "_subvsi3", "_subvdi3", "_mulvsi3", "_mulvdi3", "_negvsi2", "_negvdi2",
    "_ffssi2", "_ffsdi2", "_clz", "_clzsi2", "_clzdi2", "_ctzsi2", "_ctzdi2",
    "_popcount_tab", "_popcountsi2", "_popcountdi2", "_paritysi2", "_paritydi2",
    "_powisf2", "_powidf2", "_powixf2", "_powitf2",
    "_mulsc3", "_muldc3", "_mulxc3", "_multc3",
    "_divsc3", "_divdc3", "_divxc3", "_divtc3",
    "_bswapsi2", "_bswapdi2", "_clrsbsi2", "_clrsbdi2",
    "_fixunssfsi", "_fixunsdfsi", "_fixunsxfsi",
    "_fixsfdi", "_fixdfdi", "_fixxfdi",
    "_fixunssfdi", "_fixunsdfdi", "_fixunsxfdi",
    "_floatdisf", "_floatdidf", "_floatdixf",
    "_floatundisf", "_floatundidf", "_floatundixf",
    "_divdi3", "_moddi3", "_udivdi3", "_umoddi3", "_udiv_w_sdiv", "_udivmoddi4",
    "_enable_execute_stack",
]

# Generate per-function wrapper .c files and compile them into a library
[genrule(
    name = "gen_libgcc2_" + func.lstrip("_"),
    outs = ["libgcc2_" + func.lstrip("_") + ".c"],
    cmd = "printf '#define L" + func + "\\n#include \"libgcc2.c\"\\n' > $@",
) for func in _LIBGCC2_FUNCS]

cc_library(
    name = "libgcc2_objs",
    srcs = ["libgcc2_" + func.lstrip("_") + ".c" for func in _LIBGCC2_FUNCS],
    copts = _LIBGCC_COPTS,
    includes = _LIBGCC_INCLUDES,
    textual_hdrs = ["libgcc2.c", "libgcc2.h"],
    deps = _LIBGCC_DEPS + [":libgcc_tm"],
)

# ============================================================================
# Unwind / exception handling sources
# ============================================================================

_UNWIND_SRCS = [
    "unwind-dw2.c",
    "unwind-dw2-fde-dip.c",
    "unwind-sjlj.c",
    "unwind-c.c",
    "emutls.c",
]

_UNWIND_HDRS = glob(
    [
        "unwind-*.h",
        "unwind.h",
        "md-unwind-support.h",
        "gthr*.h",
        "gcov.h",
        "libgcov.h",
        "dfp-bit.h",
        "fp-bit.h",
        "fixed-bit.h",
        "gstdint.h",
        "config/**/*.h",
    ],
    allow_empty = True,
) + [
    # .c and .inc files textually included by unwind sources
    "unwind-dw2-fde.c",
    "unwind.inc",
]

cc_library(
    name = "libgcc_eh_objs",
    srcs = _UNWIND_SRCS,
    copts = _LIBGCC_COPTS + ["-fexceptions"],
    includes = _LIBGCC_INCLUDES + ["config", "config/i386"],
    textual_hdrs = _UNWIND_HDRS,
    deps = _LIBGCC_DEPS + [":libgcc_tm"],
)

# ============================================================================
# libgcc.a - static runtime library (combined archive)
# ============================================================================

cc_static_library(
    name = "gcc",
    deps = [":libgcc2_objs", ":libgcc_eh_objs"],
)

# libgcc_eh.a - exception handling only (for static linking with -static-libgcc)
cc_static_library(
    name = "gcc_eh",
    deps = [":libgcc_eh_objs"],
)

# ============================================================================
# libgcc_s.so - shared runtime library (built with -fPIC -DSHARED)
# ============================================================================

cc_library(
    name = "libgcc2_pic",
    srcs = ["libgcc2_" + func.lstrip("_") + ".c" for func in _LIBGCC2_FUNCS],
    copts = _LIBGCC_COPTS + ["-fPIC", "-DSHARED"],
    includes = _LIBGCC_INCLUDES,
    textual_hdrs = ["libgcc2.c", "libgcc2.h"],
    deps = _LIBGCC_DEPS + [":libgcc_tm"],
)

cc_library(
    name = "libgcc_eh_pic",
    srcs = _UNWIND_SRCS,
    copts = _LIBGCC_COPTS + ["-fPIC", "-DSHARED", "-fexceptions"],
    includes = _LIBGCC_INCLUDES + ["config", "config/i386"],
    textual_hdrs = _UNWIND_HDRS,
    deps = _LIBGCC_DEPS + [":libgcc_tm"],
)

cc_shared_library(
    name = "libgcc_s",
    deps = [":libgcc2_pic", ":libgcc_eh_pic"],
    shared_lib_name = "libgcc_s.so.1",
)
