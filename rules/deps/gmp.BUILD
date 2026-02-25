load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

# ---------- multi-function mpn files (need -DOPERATION_xxx variants) ----------

# Generated headers are in generated/ to avoid polluting iquote paths
# that Bazel adds for the repo root.
_GMP_COPTS = [
    "-DHAVE_CONFIG_H",
    "-D__GMP_WITHIN_GMP",
    "-Iexternal/+gcc_ext+gmp/generated",
]

_LOGOPS_OPS = [
    "and_n",
    "andn_n",
    "nand_n",
    "ior_n",
    "iorn_n",
    "nior_n",
    "xor_n",
    "xnor_n",
]

[cc_library(
    name = "mpn_" + op,
    srcs = ["mpn/generic/logops_n.c"],
    copts = _GMP_COPTS + ["-DOPERATION_" + op],
    deps = [":gmp_hdrs"],
) for op in _LOGOPS_OPS]

_POPHAM_OPS = [
    "popcount",
    "hamdist",
]

[cc_library(
    name = "mpn_" + op,
    srcs = ["mpn/generic/popham.c"],
    copts = _GMP_COPTS + ["-DOPERATION_" + op],
    deps = [":gmp_hdrs"],
) for op in _POPHAM_OPS]

_SEC_AORS_OPS = [
    "sec_add_1",
    "sec_sub_1",
]

[cc_library(
    name = "mpn_" + op,
    srcs = ["mpn/generic/sec_aors_1.c"],
    copts = _GMP_COPTS + ["-DOPERATION_" + op],
    deps = [":gmp_hdrs"],
) for op in _SEC_AORS_OPS]

_SEC_DIV_OPS = [
    "sec_div_qr",
    "sec_div_r",
]

[cc_library(
    name = "mpn_" + op,
    srcs = ["mpn/generic/sec_div.c"],
    copts = _GMP_COPTS + ["-DOPERATION_" + op],
    deps = [":gmp_hdrs"],
) for op in _SEC_DIV_OPS]

_SEC_PI1_DIV_OPS = [
    "sec_pi1_div_qr",
    "sec_pi1_div_r",
]

[cc_library(
    name = "mpn_" + op,
    srcs = ["mpn/generic/sec_pi1_div.c"],
    copts = _GMP_COPTS + ["-DOPERATION_" + op],
    deps = [":gmp_hdrs"],
) for op in _SEC_PI1_DIV_OPS]

# ---------- internal headers (private, not propagated to dependents) ----------

cc_library(
    name = "gmp_hdrs",
    hdrs = [
        "generated/config.h",
        "generated/gmp.h",
        "generated/gmp-mparam.h",
        "generated/fac_table.h",
        "generated/fib_table.h",
        "generated/mp_bases.h",
        "generated/sieve_table.h",
        "generated/trialdivtab.h",
        "gmp-impl.h",
        "longlong.h",
    ] + glob([
        "mpn/generic/*.h",
    ]),
    # Only used by internal GMP targets; NOT propagated externally.
    visibility = ["//visibility:private"],
)

# ---------- main library ----------

_MULTI_FUNCTION_SRCS = [
    "mpn/generic/logops_n.c",
    "mpn/generic/popham.c",
    "mpn/generic/sec_aors_1.c",
    "mpn/generic/sec_div.c",
    "mpn/generic/sec_pi1_div.c",
]

# Files that require arch-specific macros not available in the generic build
_EXCLUDED_MPN_SRCS = [
    "mpn/generic/udiv_w_sdiv.c",  # needs sdiv_qrnnd (not available on x86_64)
]

cc_library(
    name = "gmp",
    srcs = [
        # top-level sources
        "assert.c",
        "compat.c",
        "errno.c",
        "extract-dbl.c",
        "invalid.c",
        "memory.c",
        "mp_bpl.c",
        "mp_clz_tab.c",
        "mp_dv_tab.c",
        "mp_get_fns.c",
        "mp_minv_tab.c",
        "mp_set_fns.c",
        "nextprime.c",
        "primesieve.c",
        "tal-reent.c",
        "version.c",
        # generated sources
        "generated/fib_table.c",
        "generated/mp_bases.c",
        # internal headers used by .c files
        "gmp-impl.h",
        "longlong.h",
        "generated/config.h",
        "generated/gmp.h",
        "generated/gmp-mparam.h",
        "generated/fac_table.h",
        "generated/fib_table.h",
        "generated/mp_bases.h",
        "generated/sieve_table.h",
        "generated/trialdivtab.h",
        "generated/perfsqr.h",
        "generated/jacobitab.h",
    ] + glob(
        [
            "mpz/*.c",
            "mpz/*.h",
            "mpf/*.c",
            "mpf/*.h",
            "mpq/*.c",
            "mpn/generic/*.c",
            "printf/*.c",
            "scanf/*.c",
            "rand/*.c",
            "rand/*.h",
            "mpn/generic/*.h",
        ],
        exclude = _MULTI_FUNCTION_SRCS + _EXCLUDED_MPN_SRCS,
    ),
    hdrs = ["include/gmp.h"],
    copts = _GMP_COPTS,
    includes = ["include"],
    linkopts = ["-lm"],
    deps = [
        ":mpn_and_n",
        ":mpn_andn_n",
        ":mpn_nand_n",
        ":mpn_ior_n",
        ":mpn_iorn_n",
        ":mpn_nior_n",
        ":mpn_xor_n",
        ":mpn_xnor_n",
        ":mpn_popcount",
        ":mpn_hamdist",
        ":mpn_sec_add_1",
        ":mpn_sec_sub_1",
        ":mpn_sec_div_qr",
        ":mpn_sec_div_r",
        ":mpn_sec_pi1_div_qr",
        ":mpn_sec_pi1_div_r",
    ],
)
