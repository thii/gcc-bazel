load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "backtrace",
    srcs = [
        # Linux ELF configuration
        "atomic.c",
        "backtrace.c",
        "dwarf.c",
        "elf.c",
        "fileline.c",
        "mmap.c",
        "mmapio.c",
        "posix.c",
        "print.c",
        "simple.c",
        "sort.c",
        "state.c",
        # Private header
        "internal.h",
    ],
    hdrs = [
        "backtrace.h",
    ],
    copts = [
        "-DHAVE_CONFIG_H",
        "-DBACKTRACE_ELF_SIZE=64",
        "-DHAVE_DL_ITERATE_PHDR=1",
        "-DHAVE_LINK_H=1",
        "-DHAVE_MMAP=1",
        "-funwind-tables",
    ],
    includes = ["."],
    deps = [
        "//:include",
        "@gcc_config//:libbacktrace_config",
    ],
)
