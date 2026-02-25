load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "cody",
    srcs = [
        "buffer.cc",
        "client.cc",
        "fatal.cc",
        "netclient.cc",
        "netserver.cc",
        "packet.cc",
        "resolver.cc",
        "server.cc",
        # Private header
        "internal.hh",
    ],
    hdrs = ["cody.hh"],
    copts = [
        "-DHAVE_CONFIG_H",
        """-DSRCDIR='"."'""",
        "-UIN_GCC",
    ],
    includes = ["."],
    deps = [
        "@gcc_config//:libcody_config",
    ],
)
