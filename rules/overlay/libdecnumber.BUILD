load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "decnumber",
    srcs = [
        "decContext.c",
        "decNumber.c",
        "dpd/decimal128.c",
        "dpd/decimal32.c",
        "dpd/decimal64.c",
    ],
    hdrs = glob(["*.h", "dpd/*.h"]),
    copts = [
        "-DHAVE_CONFIG_H",
    ],
    includes = [".", "dpd"],
    deps = [
        "//:include",
        "@gcc_config//:libdecnumber_config",
    ],
)
