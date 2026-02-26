load("@rules_cc//cc:defs.bzl", "cc_library", "cc_shared_library")
load("@rules_cc//cc:cc_static_library.bzl", "cc_static_library")

package(default_visibility = ["//visibility:public"])

# ============================================================================
# Common compiler flags for libstdc++
# ============================================================================

_COPTS = [
    "-O2",
    "-g0",
    "-DHAVE_CONFIG_H",
    "-fPIC",
    "-nostdinc++",
    "-fno-implicit-templates",
    "-fno-implicit-inline-templates",
    "-ffunction-sections",
    "-fdata-sections",
    "-Wall",
    "-Wextra",
    "-Wno-unused-parameter",
    "-fdiagnostics-show-caret",
    # Needed for atomicity builtins
    "-D_GLIBCXX_ATOMIC_WORD_BUILTINS",
    # Emit backward-compatibility symbols for the shared library (old ABI
    # stubs gated behind #ifdef _GLIBCXX_SHARED in compatibility-*.cc,
    # list-aux-2.cc, etc.).  Harmless to include in the static archive.
    "-D_GLIBCXX_SHARED",
]

_INCLUDES = [
    "include",
    "include/std",
    "include/c_global",
    "include/x86_64-linux-gnu",
    "include/backward",
    "libsupc++",
    "config/os/gnu-linux",
    "config/cpu/generic",
    "config/locale/gnu",
    "config/io",
    "config/allocator",
]


_DEPS = [
    "@gcc_config//:libstdcxx_config",
    "//libgcc:unwind_headers",
]

# ============================================================================
# Generated config headers
# ============================================================================

# Copy c++config.h from @gcc_config into the include tree at the
# target-specific location where the standard include path expects it.
genrule(
    name = "gen_cxxconfig",
    srcs = ["@gcc_config//:libstdc++/c++config.h"],
    outs = ["include/x86_64-linux-gnu/bits/c++config.h"],
    cmd = "cp $< $@",
)

genrule(
    name = "gen_gthr",
    srcs = ["@gcc_config//:libstdc++/gthr.h"],
    outs = ["include/bits/gthr.h"],
    cmd = "cp $< $@",
)

genrule(
    name = "gen_gthr_default",
    srcs = ["@gcc_config//:libstdc++/gthr-default.h"],
    outs = ["include/bits/gthr-default.h"],
    cmd = "cp $< $@",
)

genrule(
    name = "gen_gthr_posix",
    srcs = ["@gcc_config//:libstdc++/gthr-posix.h"],
    outs = ["include/bits/gthr-posix.h"],
    cmd = "cp $< $@",
)

genrule(
    name = "gen_gthr_single",
    srcs = ["@gcc_config//:libstdc++/gthr-single.h"],
    outs = ["include/bits/gthr-single.h"],
    cmd = "cp $< $@",
)

# Target-specific platform headers
genrule(
    name = "gen_os_defines",
    srcs = ["@gcc_config//:libstdc++/os_defines.h"],
    outs = ["include/x86_64-linux-gnu/bits/os_defines.h"],
    cmd = "cp $< $@",
)

genrule(
    name = "gen_cpu_defines",
    srcs = ["@gcc_config//:libstdc++/cpu_defines.h"],
    outs = ["include/x86_64-linux-gnu/bits/cpu_defines.h"],
    cmd = "cp $< $@",
)

genrule(
    name = "gen_ctype_base",
    srcs = ["@gcc_config//:libstdc++/ctype_base.h"],
    outs = ["include/x86_64-linux-gnu/bits/ctype_base.h"],
    cmd = "cp $< $@",
)

genrule(
    name = "gen_ctype_inline",
    srcs = ["@gcc_config//:libstdc++/ctype_inline.h"],
    outs = ["include/x86_64-linux-gnu/bits/ctype_inline.h"],
    cmd = "cp $< $@",
)

genrule(
    name = "gen_c_allocator",
    srcs = ["@gcc_config//:libstdc++/c++allocator.h"],
    outs = ["include/x86_64-linux-gnu/bits/c++allocator.h"],
    cmd = "cp $< $@",
)

genrule(
    name = "gen_c_io",
    srcs = ["@gcc_config//:libstdc++/c++io.h"],
    outs = ["include/x86_64-linux-gnu/bits/c++io.h"],
    cmd = "cp $< $@",
)

genrule(
    name = "gen_c_locale",
    srcs = ["@gcc_config//:libstdc++/c++locale.h"],
    outs = ["include/x86_64-linux-gnu/bits/c++locale.h"],
    cmd = "cp $< $@",
)

genrule(
    name = "gen_basic_file",
    srcs = ["@gcc_config//:libstdc++/basic_file.h"],
    outs = ["include/x86_64-linux-gnu/bits/basic_file.h"],
    cmd = "cp $< $@",
)

genrule(
    name = "gen_c_locale_internal",
    srcs = ["@gcc_config//:libstdc++/c++locale_internal.h"],
    outs = ["include/x86_64-linux-gnu/bits/c++locale_internal.h"],
    cmd = "cp $< $@",
)

genrule(
    name = "gen_messages_members",
    srcs = ["@gcc_config//:libstdc++/messages_members.h"],
    outs = ["include/x86_64-linux-gnu/bits/messages_members.h"],
    cmd = "cp $< $@",
)

genrule(
    name = "gen_time_members",
    srcs = ["@gcc_config//:libstdc++/time_members.h"],
    outs = ["include/x86_64-linux-gnu/bits/time_members.h"],
    cmd = "cp $< $@",
)

genrule(
    name = "gen_error_constants",
    srcs = ["@gcc_config//:libstdc++/error_constants.h"],
    outs = ["include/x86_64-linux-gnu/bits/error_constants.h"],
    cmd = "cp $< $@",
)

genrule(
    name = "gen_atomic_word",
    srcs = ["@gcc_config//:libstdc++/atomic_word.h"],
    outs = ["include/x86_64-linux-gnu/bits/atomic_word.h"],
    cmd = "cp $< $@",
)

genrule(
    name = "gen_cxxabi_tweaks",
    srcs = ["@gcc_config//:libstdc++/cxxabi_tweaks.h"],
    outs = ["include/x86_64-linux-gnu/bits/cxxabi_tweaks.h"],
    cmd = "cp $< $@",
)

genrule(
    name = "gen_opt_random",
    srcs = ["@gcc_config//:libstdc++/opt_random.h"],
    outs = ["include/x86_64-linux-gnu/bits/opt_random.h"],
    cmd = "cp $< $@",
)

genrule(
    name = "gen_largefile_config",
    srcs = ["@gcc_config//:libstdc++/largefile-config.h"],
    outs = ["include/x86_64-linux-gnu/bits/largefile-config.h"],
    cmd = "cp $< $@",
)

genrule(
    name = "gen_compatibility",
    srcs = ["@gcc_config//:libstdc++/compatibility.h"],
    outs = ["include/x86_64-linux-gnu/bits/compatibility.h"],
    cmd = "cp $< $@",
)

# ============================================================================
# libsupc++ headers installed to include/bits/ (mirroring autotools symlinks)
# ============================================================================

_SUPCXX_BITS_HEADERS = [
    "atomic_lockfree_defines.h",
    "cxxabi_forced.h",
    "cxxabi_init_exception.h",
    "exception.h",
    "exception_defines.h",
    "exception_ptr.h",
    "hash_bytes.h",
    "nested_exception.h",
]

[genrule(
    name = "gen_supcxx_bits_" + hdr.replace(".", "_"),
    srcs = ["libsupc++/" + hdr],
    outs = ["include/bits/" + hdr],
    cmd = "cp $< $@",
) for hdr in _SUPCXX_BITS_HEADERS]

_GENERATED_HDRS = [
    ":gen_cxxconfig",
    ":gen_gthr",
    ":gen_gthr_default",
    ":gen_gthr_posix",
    ":gen_gthr_single",
    ":gen_os_defines",
    ":gen_cpu_defines",
    ":gen_ctype_base",
    ":gen_ctype_inline",
    ":gen_c_allocator",
    ":gen_c_io",
    ":gen_c_locale",
    ":gen_basic_file",
    ":gen_c_locale_internal",
    ":gen_messages_members",
    ":gen_time_members",
    ":gen_error_constants",
    ":gen_atomic_word",
    ":gen_cxxabi_tweaks",
    ":gen_opt_random",
    ":gen_largefile_config",
    ":gen_compatibility",
] + [":gen_supcxx_bits_" + hdr.replace(".", "_") for hdr in _SUPCXX_BITS_HEADERS]

# Collect all generated headers as a library so other targets can depend on them.
cc_library(
    name = "config_headers",
    hdrs = _GENERATED_HDRS,
    includes = ["include"],
)

# All source tree headers (include/, libsupc++, config/)
_ALL_HDRS = glob(
    [
        "include/**",
        "libsupc++/*.h",
        "config/os/gnu-linux/*.h",
        "config/cpu/generic/**/*.h",
        "config/locale/gnu/*.h",
        "config/io/*.h",
        "config/allocator/*.h",
    ],
    exclude = [
        "include/Makefile*",
        "include/precompiled/**",
    ],
) + [
    # Standard C++ headers without extensions
    "libsupc++/compare",
    "libsupc++/exception",
    "libsupc++/initializer_list",
    "libsupc++/new",
    "libsupc++/typeinfo",
]

# ============================================================================
# atomicity.cc — generated from config/cpu/generic/atomicity_builtins
# ============================================================================

genrule(
    name = "gen_atomicity_cc",
    srcs = ["config/cpu/generic/atomicity_builtins/atomicity.h"],
    outs = ["atomicity.cc"],
    cmd = "cp $< $@",
)

# ============================================================================
# libsupc++ — C++ support library (exceptions, RTTI, new/delete)
# ============================================================================

_SUPCXX_SRCS = [
    "libsupc++/array_type_info.cc",
    "libsupc++/atexit_arm.cc",
    "libsupc++/atexit_thread.cc",
    "libsupc++/bad_alloc.cc",
    "libsupc++/bad_array_length.cc",
    "libsupc++/bad_array_new.cc",
    "libsupc++/bad_cast.cc",
    "libsupc++/bad_typeid.cc",
    "libsupc++/class_type_info.cc",
    "libsupc++/del_op.cc",
    "libsupc++/del_opa.cc",
    "libsupc++/del_opant.cc",
    "libsupc++/del_opnt.cc",
    "libsupc++/del_ops.cc",
    "libsupc++/del_opsa.cc",
    "libsupc++/del_opv.cc",
    "libsupc++/del_opva.cc",
    "libsupc++/del_opvant.cc",
    "libsupc++/del_opvnt.cc",
    "libsupc++/del_opvs.cc",
    "libsupc++/del_opvsa.cc",
    "libsupc++/dyncast.cc",
    "libsupc++/eh_alloc.cc",
    "libsupc++/eh_arm.cc",
    "libsupc++/eh_aux_runtime.cc",
    "libsupc++/eh_call.cc",
    "libsupc++/eh_catch.cc",
    "libsupc++/eh_exception.cc",
    "libsupc++/eh_globals.cc",
    "libsupc++/eh_personality.cc",
    "libsupc++/eh_ptr.cc",
    "libsupc++/eh_term_handler.cc",
    "libsupc++/eh_terminate.cc",
    "libsupc++/eh_throw.cc",
    "libsupc++/eh_tm.cc",
    "libsupc++/eh_type.cc",
    "libsupc++/eh_unex_handler.cc",
    "libsupc++/enum_type_info.cc",
    "libsupc++/function_type_info.cc",
    "libsupc++/fundamental_type_info.cc",
    "libsupc++/guard.cc",
    "libsupc++/guard_error.cc",
    "libsupc++/hash_bytes.cc",
    "libsupc++/nested_exception.cc",
    "libsupc++/new_handler.cc",
    "libsupc++/new_op.cc",
    "libsupc++/new_opa.cc",
    "libsupc++/new_opant.cc",
    "libsupc++/new_opnt.cc",
    "libsupc++/new_opv.cc",
    "libsupc++/new_opva.cc",
    "libsupc++/new_opvant.cc",
    "libsupc++/new_opvnt.cc",
    "libsupc++/pbase_type_info.cc",
    "libsupc++/pmem_type_info.cc",
    "libsupc++/pointer_type_info.cc",
    "libsupc++/pure.cc",
    "libsupc++/si_class_type_info.cc",
    "libsupc++/tinfo.cc",
    "libsupc++/tinfo2.cc",
    "libsupc++/vec.cc",
    "libsupc++/vmi_class_type_info.cc",
    "libsupc++/vterminate.cc",
    "libsupc++/vtv_stubs.cc",
]

cc_library(
    name = "supc++",
    srcs = _SUPCXX_SRCS + [":gen_atomicity_cc"],
    copts = _COPTS,
    includes = _INCLUDES,
    textual_hdrs = _ALL_HDRS,
    deps = _DEPS + [":config_headers"],
)

# ============================================================================
# cp-demangle.c — C source from libiberty, compiled with -DIN_GLIBCPP_V3
# ============================================================================

genrule(
    name = "gen_cp_demangle_c",
    srcs = ["//libiberty:cp-demangle.c"],
    outs = ["cp-demangle.c"],
    cmd = "cp $< $@",
)

genrule(
    name = "gen_cp_demangle_h",
    srcs = ["//libiberty:cp-demangle.h"],
    outs = ["cp-demangle.h"],
    cmd = "cp $< $@",
)

cc_library(
    name = "cp_demangle",
    srcs = [":gen_cp_demangle_c"],
    copts = ["-O2", "-g0", "-DIN_GLIBCPP_V3", "-Wno-error"],
    textual_hdrs = [":gen_cp_demangle_h"],
    deps = [
        "//:include",
        "@gcc_config//:libiberty_config",
    ],
)

# ============================================================================
# c++98 — C++98/03 runtime component
# ============================================================================

_CXX98_SRCS = [
    "src/c++98/bitmap_allocator.cc",
    "src/c++98/pool_allocator.cc",
    "src/c++98/mt_allocator.cc",
    "src/c++98/codecvt.cc",
    "src/c++98/complex_io.cc",
    "src/c++98/globals_io.cc",
    "src/c++98/hash_tr1.cc",
    "src/c++98/hashtable_tr1.cc",
    "src/c++98/ios_failure.cc",
    "src/c++98/ios_init.cc",
    "src/c++98/ios_locale.cc",
    "src/c++98/list.cc",
    "src/c++98/list-aux.cc",
    "src/c++98/list-aux-2.cc",
    "src/c++98/list_associated.cc",
    "src/c++98/list_associated-2.cc",
    "src/c++98/locale.cc",
    "src/c++98/locale_facets.cc",
    "src/c++98/math_stubs_float.cc",
    "src/c++98/math_stubs_long_double.cc",
    "src/c++98/stdexcept.cc",
    "src/c++98/strstream.cc",
    "src/c++98/tree.cc",
    "src/c++98/istream.cc",
    "src/c++98/istream-string.cc",
    "src/c++98/streambuf.cc",
    "src/c++98/valarray.cc",
    # Dual-ABI cow source
    "src/c++98/cow-istream-string.cc",
    # Extern template instantiations
    "src/c++98/allocator-inst.cc",
    "src/c++98/concept-inst.cc",
    "src/c++98/ext-inst.cc",
    "src/c++98/misc-inst.cc",
    # Parallel mode
    "src/c++98/parallel_settings.cc",
]

# Host-specific locale sources (symlinked from config/locale/gnu/ in autotools build)
_CXX98_HOST_SRCS = [
    "config/locale/gnu/codecvt_members.cc",
    "config/locale/gnu/collate_members.cc",
    "config/locale/gnu/messages_members.cc",
    "config/locale/gnu/monetary_members.cc",
    "config/locale/gnu/numeric_members.cc",
    "config/locale/gnu/time_members.cc",
]

# c++locale.cc is c_locale.cc with special compilation (fimplicit-templates)
genrule(
    name = "gen_cxx_locale_cc",
    srcs = ["config/locale/gnu/c_locale.cc"],
    outs = ["c++locale.cc"],
    cmd = "cp $< $@",
)

# Dual-ABI cow variants: same source as base, compiled with -D_GLIBCXX_USE_CXX11_ABI=0
_CXX98_COW_MEMBERS = [
    ("collate_members_cow", "config/locale/gnu/collate_members.cc"),
    ("messages_members_cow", "config/locale/gnu/messages_members.cc"),
    ("monetary_members_cow", "config/locale/gnu/monetary_members.cc"),
    ("numeric_members_cow", "config/locale/gnu/numeric_members.cc"),
]

[genrule(
    name = "gen_" + name,
    srcs = [src],
    outs = [name + ".cc"],
    cmd = "cp $< $@",
) for name, src in _CXX98_COW_MEMBERS]

cc_library(
    name = "c++98_cow",
    srcs = [name + ".cc" for name, _ in _CXX98_COW_MEMBERS],
    copts = _COPTS + [
        "-std=gnu++98",
        "-D_GLIBCXX_USE_CXX11_ABI=0",
        "-fimplicit-templates",
    ],
    includes = _INCLUDES,
    textual_hdrs = _ALL_HDRS,
    deps = _DEPS + [":config_headers"],
)

cc_library(
    name = "c++98",
    srcs = _CXX98_SRCS + _CXX98_HOST_SRCS + [":gen_cxx_locale_cc"],
    copts = _COPTS + ["-std=gnu++98"],
    includes = _INCLUDES,
    textual_hdrs = _ALL_HDRS + glob([
        "config/locale/gnu/*.cc",
        "config/os/gnu-linux/*.cc",
        "src/shared/*.cc",
        "src/c++98/*.cc",
    ], allow_empty = True),
    deps = _DEPS + [":config_headers", ":c++98_cow"],
)

# ============================================================================
# c++11 — C++11 runtime component
# ============================================================================

_CXX11_SRCS = [
    "src/c++11/assert_fail.cc",
    "src/c++11/chrono.cc",
    "src/c++11/codecvt.cc",
    "src/c++11/condition_variable.cc",
    "src/c++11/cow-stdexcept.cc",
    "src/c++11/cow-system_error.cc",
    "src/c++11/ctype.cc",
    "src/c++11/debug.cc",
    "src/c++11/functexcept.cc",
    "src/c++11/functional.cc",
    "src/c++11/futex.cc",
    "src/c++11/future.cc",
    "src/c++11/hash_c++0x.cc",
    "src/c++11/hashtable_c++0x.cc",
    "src/c++11/ios.cc",
    "src/c++11/ios_errcat.cc",
    "src/c++11/locale_init.cc",
    "src/c++11/localename.cc",
    "src/c++11/mutex.cc",
    "src/c++11/random.cc",
    "src/c++11/regex.cc",
    "src/c++11/shared_ptr.cc",
    "src/c++11/snprintf_lite.cc",
    "src/c++11/system_error.cc",
    "src/c++11/thread.cc",
    # Dual-ABI sources
    "src/c++11/cow-locale_init.cc",
    "src/c++11/cow-shim_facets.cc",
    "src/c++11/cxx11-hash_tr1.cc",
    "src/c++11/cxx11-ios_failure.cc",
    "src/c++11/cxx11-shim_facets.cc",
    "src/c++11/cxx11-stdexcept.cc",
    # Freestanding sources
    "src/c++11/limits.cc",
    "src/c++11/placeholders.cc",
    # Extern template instantiations
    "src/c++11/ext11-inst.cc",
    "src/c++11/fstream-inst.cc",
    "src/c++11/ios-inst.cc",
    "src/c++11/iostream-inst.cc",
    "src/c++11/istream-inst.cc",
    "src/c++11/locale-inst.cc",
    "src/c++11/ostream-inst.cc",
    "src/c++11/sstream-inst.cc",
    "src/c++11/streambuf-inst.cc",
    "src/c++11/string-inst.cc",
    "src/c++11/string-io-inst.cc",
    "src/c++11/wlocale-inst.cc",
    "src/c++11/wstring-inst.cc",
    "src/c++11/wstring-io-inst.cc",
    # Dual-ABI string instantiations
    "src/c++11/cow-fstream-inst.cc",
    "src/c++11/cow-sstream-inst.cc",
    "src/c++11/cow-string-inst.cc",
    "src/c++11/cow-string-io-inst.cc",
    "src/c++11/cow-wstring-inst.cc",
    "src/c++11/cow-wstring-io-inst.cc",
    "src/c++11/cxx11-locale-inst.cc",
    "src/c++11/cxx11-wlocale-inst.cc",
    "src/c++11/sso_string.cc",
]

# Host-specific sources (symlinked in autotools build)
_CXX11_HOST_SRCS = [
    "config/os/gnu-linux/ctype_configure_char.cc",
]

# basic_file.cc is basic_file_stdio.cc renamed
genrule(
    name = "gen_basic_file_cc",
    srcs = ["config/io/basic_file_stdio.cc"],
    outs = ["basic_file.cc"],
    cmd = "cp $< $@",
)

# ctype_members.cc from config/locale/gnu (set by CCTYPE_CC)
genrule(
    name = "gen_ctype_members_cc",
    srcs = ["config/locale/gnu/ctype_members.cc"],
    outs = ["ctype_members.cc"],
    cmd = "cp $< $@",
)

cc_library(
    name = "c++11",
    srcs = _CXX11_SRCS + _CXX11_HOST_SRCS + [
        ":gen_basic_file_cc",
        ":gen_ctype_members_cc",
    ],
    copts = _COPTS + ["-std=gnu++11", "-fchar8_t"],
    includes = _INCLUDES,
    textual_hdrs = _ALL_HDRS + glob([
        "config/locale/gnu/*.cc",
        "config/os/gnu-linux/*.cc",
        "config/io/*.cc",
        "src/c++11/*.h",
        "src/c++11/*.cc",
        "src/shared/*.cc",
    ], allow_empty = True),
    deps = _DEPS + [":config_headers"],
)

# ============================================================================
# c++17 — C++17 runtime component
# ============================================================================

_CXX17_SRCS = [
    "src/c++17/floating_from_chars.cc",
    "src/c++17/floating_to_chars.cc",
    "src/c++17/fs_dir.cc",
    "src/c++17/fs_ops.cc",
    "src/c++17/fs_path.cc",
    "src/c++17/memory_resource.cc",
    # Dual-ABI filesystem sources
    "src/c++17/cow-fs_dir.cc",
    "src/c++17/cow-fs_ops.cc",
    "src/c++17/cow-fs_path.cc",
    # Extern template instantiations
    "src/c++17/ostream-inst.cc",
    "src/c++17/string-inst.cc",
    "src/c++17/cow-string-inst.cc",
]

cc_library(
    name = "c++17",
    srcs = _CXX17_SRCS,
    copts = _COPTS + ["-std=gnu++17", "-fimplicit-templates"],
    includes = _INCLUDES,
    textual_hdrs = _ALL_HDRS + glob([
        "src/filesystem/*.h",
        "src/c++17/*.cc",
        "src/c++17/*.h",
        "src/c++17/**/*.h",
        "src/c++17/**/*.c",
    ], allow_empty = True),
    deps = _DEPS + [":config_headers"],
)

# ============================================================================
# c++20 — C++20 runtime component
# ============================================================================

_CXX20_SRCS = [
    "src/c++20/tzdb.cc",
    "src/c++20/atomic.cc",
    "src/c++20/clock.cc",
    "src/c++20/syncbuf.cc",
    # Extern template instantiations
    "src/c++20/sstream-inst.cc",
]

# format.cc needs -std=gnu++26 and -fno-access-control
cc_library(
    name = "c++20_format",
    srcs = ["src/c++20/format.cc"],
    copts = _COPTS + ["-std=gnu++26", "-fimplicit-templates", "-fno-access-control"],
    includes = _INCLUDES,
    textual_hdrs = _ALL_HDRS + ["src/c++26/text_encoding.cc"],
    deps = _DEPS + [":config_headers"],
)

# Generate tzdata.zi.h for embedded timezone data
genrule(
    name = "gen_tzdata_zi_h",
    srcs = ["src/c++20/tzdata.zi"],
    outs = ["tzdata.zi.h"],
    cmd = """
        echo 'static const char tzdata_chars[] = R"__libstdcxx__(' > $@
        cat $< >> $@
        echo ')__libstdcxx__";' >> $@
    """,
)

cc_library(
    name = "c++20",
    srcs = _CXX20_SRCS,
    copts = _COPTS + ["-std=gnu++20", "-fimplicit-templates", "-I$(GENDIR)/external/+gcc_ext+gcc/libstdc++-v3"],
    includes = _INCLUDES,
    textual_hdrs = _ALL_HDRS + [":gen_tzdata_zi_h"],
    deps = _DEPS + [":config_headers", ":c++20_format"],
)

# ============================================================================
# c++23 — C++23 runtime component
# ============================================================================

cc_library(
    name = "c++23_print",
    srcs = ["src/c++23/print.cc"],
    copts = _COPTS + ["-std=gnu++26", "-fimplicit-templates"],
    includes = _INCLUDES,
    textual_hdrs = _ALL_HDRS,
    deps = _DEPS + [":config_headers"],
)

cc_library(
    name = "c++23",
    srcs = ["src/c++23/stacktrace.cc"],
    copts = _COPTS + ["-std=gnu++23", "-fimplicit-templates"],
    includes = _INCLUDES,
    textual_hdrs = _ALL_HDRS,
    deps = _DEPS + [":config_headers", ":c++23_print"],
)

# ============================================================================
# c++26 — C++26 runtime component
# ============================================================================

cc_library(
    name = "c++26",
    srcs = [
        "src/c++26/debugging.cc",
        "src/c++26/text_encoding.cc",
    ],
    copts = _COPTS + ["-std=gnu++26", "-fimplicit-templates"],
    includes = _INCLUDES,
    textual_hdrs = _ALL_HDRS,
    deps = _DEPS + [":config_headers"],
)

# ============================================================================
# filesystem — Filesystem TS (separate library, also included in libstdc++)
# ============================================================================

cc_library(
    name = "filesystem",
    srcs = [
        "src/filesystem/dir.cc",
        "src/filesystem/ops.cc",
        "src/filesystem/path.cc",
        # Dual-ABI sources
        "src/filesystem/cow-dir.cc",
        "src/filesystem/cow-ops.cc",
        "src/filesystem/cow-path.cc",
    ],
    copts = _COPTS + ["-std=gnu++17"],
    includes = _INCLUDES,
    textual_hdrs = _ALL_HDRS + glob(["src/filesystem/*.h", "src/filesystem/*.cc"], allow_empty = True),
    deps = _DEPS + [":config_headers"],
)

# ============================================================================
# Compatibility sources (linked into libstdc++.so, not the convenience libs)
# ============================================================================

cc_library(
    name = "compat_c++98",
    srcs = [
        "src/c++98/compatibility.cc",
        "src/c++98/compatibility-debug_list.cc",
        "src/c++98/compatibility-debug_list-2.cc",
    ],
    copts = _COPTS + ["-std=gnu++98"],
    includes = _INCLUDES,
    textual_hdrs = _ALL_HDRS + glob(["src/c++98/*.cc"], allow_empty = True),
    deps = _DEPS + [":config_headers"],
)

cc_library(
    name = "compat_c++11",
    srcs = [
        "src/c++11/compatibility-atomic-c++0x.cc",
        "src/c++11/compatibility-c++0x.cc",
        "src/c++11/compatibility-chrono.cc",
        "src/c++11/compatibility-condvar.cc",
        "src/c++11/compatibility-thread-c++0x.cc",
    ],
    copts = _COPTS + ["-std=gnu++11"],
    includes = _INCLUDES,
    textual_hdrs = _ALL_HDRS,
    deps = _DEPS + [":config_headers"],
)

# ============================================================================
# libbacktrace — stacktrace support (C sources from ../libbacktrace)
# Compiled with backtrace-rename.h to prefix all symbols with __glibcxx_.
# ============================================================================

# Copy libbacktrace C sources into this package so they can be compiled
# with libstdc++-specific flags and the rename header.
_LIBBACKTRACE_SRCS = [
    "atomic.c",
    "backtrace.c",
    "dwarf.c",
    "elf.c",
    "fileline.c",
    "mmap.c",
    "mmapio.c",
    "posix.c",
    "simple.c",
    "sort.c",
    "state.c",
]

[genrule(
    name = "gen_libbt_" + src.replace(".", "_"),
    srcs = ["//libbacktrace:" + src],
    outs = ["libbacktrace/" + src],
    cmd = "cp $< $@",
) for src in _LIBBACKTRACE_SRCS]

genrule(
    name = "gen_libbt_cp_demangle",
    srcs = ["//libiberty:cp-demangle.c"],
    outs = ["libbacktrace/cp-demangle.c"],
    cmd = "cp $< $@",
)

genrule(
    name = "gen_libbt_cp_demangle_h",
    srcs = ["//libiberty:cp-demangle.h"],
    outs = ["libbacktrace/cp-demangle.h"],
    cmd = "cp $< $@",
)

genrule(
    name = "gen_backtrace_supported_h",
    srcs = ["@gcc_config//:libstdc++/backtrace-supported.h"],
    outs = ["libbacktrace/backtrace-supported.h"],
    cmd = "cp $< $@",
)

cc_library(
    name = "stdc++_libbacktrace",
    srcs = ["libbacktrace/" + src for src in _LIBBACKTRACE_SRCS] + [
        "libbacktrace/cp-demangle.c",
    ],
    copts = [
        "-O2",
        "-g0",
        "-fPIC",
        "-D_GNU_SOURCE",
        "-DHAVE_ATOMIC_FUNCTIONS=1",
        "-DHAVE_SYNC_FUNCTIONS=1",
        "-DHAVE_DL_ITERATE_PHDR=1",
        "-DHAVE_FCNTL=1",
        "-DBACKTRACE_ELF_SIZE=64",
        "-funwind-tables",
        "-W",
        "-Wall",
        "-Wno-unused-but-set-variable",
        "-include",
        "libstdc++-v3/src/libbacktrace/backtrace-rename.h",
    ],
    textual_hdrs = [
        "src/libbacktrace/backtrace-rename.h",
        ":gen_backtrace_supported_h",
        ":gen_libbt_cp_demangle_h",
    ],
    includes = ["libbacktrace"],
    deps = [
        "//:include",
        "//libbacktrace:backtrace",
        "@gcc_config//:libbacktrace_config",
        "@gcc_config//:libiberty_config",
    ],
)

# ============================================================================
# contract26 — C++26 contracts experimental support
# ============================================================================

cc_library(
    name = "contract26",
    srcs = ["src/experimental/contract26.cc"],
    copts = _COPTS + ["-std=gnu++26", "-fimplicit-templates", "-fcontracts"],
    includes = _INCLUDES,
    textual_hdrs = _ALL_HDRS,
    deps = _DEPS + [":config_headers"],
)

# ============================================================================
# libstdc++.a — combined static archive
# ============================================================================

cc_static_library(
    name = "stdc++",
    deps = [
        ":supc++",
        ":cp_demangle",
        ":c++98",
        ":c++11",
        ":c++17",
        ":c++20",
        ":c++23",
        ":c++26",
        ":filesystem",
        ":compat_c++98",
        ":compat_c++11",
    ],
)

# ============================================================================
# libstdc++exp.a — experimental/supplementary static archive
# Matches autotools' libstdc++exp.a: c++23, c++26, filesystem, libbacktrace,
# and experimental/contract26.
# ============================================================================

cc_static_library(
    name = "stdc++exp",
    deps = [
        ":c++23",
        ":c++26",
        ":filesystem",
        ":stdc++_libbacktrace",
        ":contract26",
    ],
)

# ============================================================================
# libstdc++.so — shared library
# ============================================================================

# Preprocess the version script: strip comment lines (# ...) then preprocess.
# Matches the autotools recipe: egrep -v '^[ \t]*#(#| |$)' | cpp -E -P
genrule(
    name = "gen_version_script",
    srcs = [
        "config/abi/pre/gnu.ver",
        "@gcc_config//:libstdc++/config.h",
    ],
    outs = ["libstdc++.ver"],
    cmd = """
        grep -E -v '^[[:space:]]*#(#| |$$)' $(location config/abi/pre/gnu.ver) | \
        gcc -E -P -include $(location @gcc_config//:libstdc++/config.h) \
            -x assembler-with-cpp - > $@
    """,
)

cc_shared_library(
    name = "stdc++_shared",
    deps = [
        ":supc++",
        ":cp_demangle",
        ":c++98",
        ":c++98_cow",
        ":c++11",
        ":c++17",
        ":c++20",
        ":c++20_format",
        ":c++23",
        ":c++23_print",
        ":c++26",
        ":filesystem",
        ":compat_c++98",
        ":compat_c++11",
    ],
    shared_lib_name = "libstdc++.so.6",
    additional_linker_inputs = [":gen_version_script"],
    user_link_flags = [
        "-Wl,--version-script=$(location :gen_version_script)",
        # text_encoding.cc is compiled into both c++20_format (as textual_hdr)
        # and c++26 (as source).  Both are whole-archived here so the linker
        # sees identical duplicate definitions.
        "-Wl,--allow-multiple-definition",
        "-lm",
    ],
)

# ============================================================================
# Headers — for distribution
# ============================================================================

filegroup(
    name = "headers",
    srcs = glob(
        [
            "include/**",
            "libsupc++/compare",
            "libsupc++/cxxabi.h",
            "libsupc++/exception",
            "libsupc++/initializer_list",
            "libsupc++/new",
            "libsupc++/typeinfo",
            "libsupc++/cxxabi_forced.h",
            "libsupc++/cxxabi_init_exception.h",
            "libsupc++/exception_defines.h",
            "libsupc++/exception_ptr.h",
            "libsupc++/exception.h",
            "libsupc++/hash_bytes.h",
            "libsupc++/nested_exception.h",
            "libsupc++/atomic_lockfree_defines.h",
        ],
        exclude = [
            "include/Makefile*",
            "include/precompiled/**",
            "include/stamp-*",
        ],
    ) + _GENERATED_HDRS,
)
