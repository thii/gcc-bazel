load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

genrule(
    name = "gen_localedir_h",
    outs = ["localedir.h"],
    cmd = """echo '#define LOCALEDIR "/usr/local/share/locale"' > $@""",
)

cc_library(
    name = "cpp",
    srcs = [
        "charset.cc",
        "directives.cc",
        "errors.cc",
        "expr.cc",
        "files.cc",
        "identifiers.cc",
        "init.cc",
        "lex.cc",
        "line-map.cc",
        "macro.cc",
        "mkdeps.cc",
        "pch.cc",
        "symtab.cc",
        "traditional.cc",
        # Private/generated headers
        ":gen_localedir_h",
        "internal.h",
        "system.h",
        "ucnid.h",
        "uname2c.h",
        "generated_cpp_wcwidth.h",
        "combining-chars.inc",
        "printable-chars.inc",
    ],
    hdrs = glob(["include/*.h"]),
    copts = [
        "-DHAVE_CONFIG_H",
        "-UIN_GCC",
    ],
    includes = [
        ".",
        "include",
    ],
    deps = [
        "//:include",
        "//gcc:gcc_headers",
        "//libiberty:iberty",
        "@gcc_config//:libcpp_config",
    ],
)
