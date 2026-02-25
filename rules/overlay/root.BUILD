load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

# Public headers in include/ used by all GCC components.
cc_library(
    name = "include",
    hdrs = glob(["include/**/*.h", "include/**/*.def"]),
    includes = ["include"],
)

# c++tools sources (textually included by gcc/cp/mapper-resolver.cc)
cc_library(
    name = "cxxtools",
    hdrs = glob(["c++tools/*.h"]),
    textual_hdrs = ["c++tools/resolver.cc"],
    strip_include_prefix = "",
)
