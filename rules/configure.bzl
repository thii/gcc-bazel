"Repository rule that provides pre-generated GCC config headers."

# Map of label (in //rules/config/x86_64-linux-gnu) -> destination path in the repo.
_CONFIG_HEADERS = {
    "gcc/auto-host.h": "gcc/auto-host.h",
    "gcc/bconfig.h": "gcc/bconfig.h",
    "gcc/config.h": "gcc/config.h",
    "gcc/configargs.h": "gcc/configargs.h",
    "gcc/plugin-version.h": "gcc/plugin-version.h",
    "gcc/tconfig.h": "gcc/tconfig.h",
    "gcc/tm.h": "gcc/tm.h",
    "gcc/tm_p.h": "gcc/tm_p.h",
    "libcpp/config.h": "libcpp/config.h",
    "libiberty/config.h": "libiberty/config.h",
    "libdecnumber/config.h": "libdecnumber/config.h",
    "libdecnumber/gstdint.h": "libdecnumber/gstdint.h",
    "libbacktrace/config.h": "libbacktrace/config.h",
    "libbacktrace/backtrace-supported.h": "libbacktrace/backtrace-supported.h",
    "libcody/config.h": "libcody/config.h",
    "libgcc/config.h": "libgcc/config.h",
    "libgcc/auto-target.h": "libgcc/auto-target.h",
}

def _gcc_configure_impl(repository_ctx):
    # Copy each pre-generated config header into the repository.
    for src_file, dst in _CONFIG_HEADERS.items():
        label = Label("//rules/config/x86_64-linux-gnu:" + src_file)
        content = repository_ctx.read(label)
        repository_ctx.file(dst, content)

    repository_ctx.file("BUILD.bazel", _BUILD_FILE_CONTENT)

_BUILD_FILE_CONTENT = """\
load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

# GCC config headers (from gcc/ configure)
cc_library(
    name = "gcc_config",
    hdrs = glob(["gcc/*.h"], allow_empty = True),
    includes = ["gcc"],
)

# GCC bconfig (for build-time / generator programs)
cc_library(
    name = "gcc_bconfig",
    hdrs = glob(["gcc/bconfig.h", "gcc/auto-host.h"], allow_empty = True),
    includes = ["gcc"],
)

# libcpp config headers
cc_library(
    name = "libcpp_config",
    hdrs = glob(["libcpp/*.h"], allow_empty = True),
    includes = ["libcpp"],
)

# libiberty config headers
cc_library(
    name = "libiberty_config",
    hdrs = glob(["libiberty/*.h"], allow_empty = True),
    includes = ["libiberty"],
)

# libdecnumber config headers
cc_library(
    name = "libdecnumber_config",
    hdrs = glob(["libdecnumber/*.h"], allow_empty = True),
    includes = ["libdecnumber"],
)

# libbacktrace config headers
cc_library(
    name = "libbacktrace_config",
    hdrs = glob(["libbacktrace/*.h"], allow_empty = True),
    includes = ["libbacktrace"],
)

# libcody config headers
cc_library(
    name = "libcody_config",
    hdrs = glob(["libcody/*.h"], allow_empty = True),
    includes = ["libcody"],
)

# libgcc config headers
cc_library(
    name = "libgcc_config",
    hdrs = glob(["libgcc/*.h"], allow_empty = True),
    includes = ["libgcc"],
)
"""

gcc_configure = repository_rule(
    implementation = _gcc_configure_impl,
    doc = "Provides pre-generated GCC config headers for x86_64-linux-gnu.",
)
