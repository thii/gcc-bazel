"Module extension for GCC source, external dependencies, and configure."

load("//rules:configure.bzl", "gcc_configure")
load("//rules:dep_source.bzl", "dep_source")
load("//rules:gcc_source.bzl", "gcc_source")
load("//rules:sysroot.bzl", "sysroot")

_GCC_COMMIT = "8eb03ad712bdbd31f9a1c84b72bcbf0c5ef1b722"

def _gcc_ext_impl(module_ctx):
    gcc_source(
        name = "gcc",
        urls = [
            "https://github.com/gcc-mirror/gcc/archive/%s.tar.gz" % _GCC_COMMIT,
        ],
        strip_prefix = "gcc-%s" % _GCC_COMMIT,
        sha256 = "1bd97fb785cd22e4f39c8ec89665cadeec65f30dfb29138fbccad8b6303209d7",
    )

    # Provide pre-generated config headers (from rules/config/x86_64-linux-gnu/)
    gcc_configure(name = "gcc_config")

    # Capture host sysroot (headers, libraries, binutils) for hermetic builds
    sysroot(name = "sysroot")

    dep_source(
        name = "gmp",
        urls = [
            "https://ftpmirror.gnu.org/gnu/gmp/gmp-6.3.0.tar.xz",
            "https://ftp.gnu.org/gnu/gmp/gmp-6.3.0.tar.xz",
            "https://gmplib.org/download/gmp/gmp-6.3.0.tar.xz",
        ],
        sha256 = "a3c2b80201b89e68616f4ad30bc66aee4927c3ce50e33929ca819d5c43538898",
        strip_prefix = "gmp-6.3.0",
        build_file = Label("//rules/deps:gmp.BUILD"),
        generated_files = {
            Label("//rules/deps/gmp:config.h"): "generated/config.h",
            Label("//rules/deps/gmp:gmp.h"): "generated/gmp.h",
            Label("//rules/deps/gmp:fac_table.h"): "generated/fac_table.h",
            Label("//rules/deps/gmp:fib_table.h"): "generated/fib_table.h",
            Label("//rules/deps/gmp:fib_table.c"): "generated/fib_table.c",
            Label("//rules/deps/gmp:mp_bases.h"): "generated/mp_bases.h",
            Label("//rules/deps/gmp:mp_bases.c"): "generated/mp_bases.c",
            Label("//rules/deps/gmp:sieve_table.h"): "generated/sieve_table.h",
            Label("//rules/deps/gmp:trialdivtab.h"): "generated/trialdivtab.h",
            Label("//rules/deps/gmp:perfsqr.h"): "generated/perfsqr.h",
            Label("//rules/deps/gmp:jacobitab.h"): "generated/jacobitab.h",
            Label("//rules/deps/gmp:gmp-mparam.h"): "generated/gmp-mparam.h",
        },
        copy_files = {
            "generated/gmp.h": "include/gmp.h",
        },
    )

    dep_source(
        name = "mpfr",
        urls = [
            "https://ftpmirror.gnu.org/gnu/mpfr/mpfr-4.2.1.tar.xz",
            "https://ftp.gnu.org/gnu/mpfr/mpfr-4.2.1.tar.xz",
            "https://www.mpfr.org/mpfr-4.2.1/mpfr-4.2.1.tar.xz",
        ],
        sha256 = "277807353a6726978996945af13e52829e3abd7a9a5b7fb2793894e18f1fcbb2",
        strip_prefix = "mpfr-4.2.1",
        build_file = Label("//rules/deps:mpfr.BUILD"),
        generated_files = {
            Label("//rules/deps/mpfr:config.h"): "generated/config.h",
            Label("//rules/deps/mpfr:mparam.h"): "src/mparam.h",
            Label("//rules/deps/mpfr:get_patches.c"): "src/get_patches.c",
        },
        copy_files = {
            "src/mpfr.h": "include/mpfr.h",
            "src/mpf2mpfr.h": "include/mpf2mpfr.h",
        },
    )

    dep_source(
        name = "mpc",
        urls = [
            "https://ftpmirror.gnu.org/gnu/mpc/mpc-1.3.1.tar.gz",
            "https://ftp.gnu.org/gnu/mpc/mpc-1.3.1.tar.gz",
        ],
        sha256 = "ab642492f5cf882b74aa0cb730cd410a81edcdbec895183ce930e706c1c759b8",
        strip_prefix = "mpc-1.3.1",
        build_file = Label("//rules/deps:mpc.BUILD"),
        generated_files = {
            Label("//rules/deps/mpc:config.h"): "generated/config.h",
        },
        copy_files = {
            "src/mpc.h": "include/mpc.h",
        },
    )

gcc_ext = module_extension(
    implementation = _gcc_ext_impl,
)
