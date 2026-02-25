load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "mpc",
    srcs = glob(
        ["src/*.c"],
        exclude = [
            # Only used with --enable-logging
            "src/logging.c",
        ],
    ) + glob([
        "src/*.h",
    ]) + [
        "generated/config.h",
    ],
    hdrs = ["include/mpc.h"],
    copts = [
        "-DHAVE_CONFIG_H",
        "-Iexternal/+gcc_ext+mpc/generated",
        "-Iexternal/+gcc_ext+mpc/src",
    ],
    includes = ["include"],
    deps = [
        "@gmp",
        "@mpfr",
    ],
)
