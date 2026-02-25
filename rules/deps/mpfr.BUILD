load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

# Files that are ONLY textually #include'd — never compiled as standalone.
_TEXTUAL_ONLY = [
    "src/round_raw_generic.c",
    "src/jyn_asympt.c",
    "src/add1sp1_extracted.c",
    "src/mul_1_extracted.c",
    "src/sub1sp1_extracted.c",
]

# Files compiled standalone AND textually #include'd by others.
# They must appear in both srcs and textual_hdrs.
_DUAL_PURPOSE = [
    "src/lngamma.c",
    "src/pow_si.c",
    "src/pow_ui.c",
]

cc_library(
    name = "mpfr",
    srcs = glob(
        ["src/*.c"],
        exclude = _TEXTUAL_ONLY,
    ) + glob([
        "src/*.h",
        "src/x86_64/*.h",
        "src/generic/*.h",
        "src/generic/coverage/*.h",
    ]) + [
        "generated/config.h",
    ],
    hdrs = [
        "include/mpfr.h",
        "include/mpf2mpfr.h",
    ],
    # Make textually-included .c files visible in the sandbox for all compile actions.
    textual_hdrs = _TEXTUAL_ONLY + _DUAL_PURPOSE,
    copts = [
        "-DHAVE_CONFIG_H",
        "-Iexternal/+gcc_ext+mpfr/generated",
        "-Iexternal/+gcc_ext+mpfr/src",
    ],
    includes = ["include"],
    deps = ["@gmp"],
)
