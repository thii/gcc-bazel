"Repository rule to capture host sysroot (headers, libraries, binutils) for hermetic builds."

_BINUTILS = [
    "ar",
    "as",
    "ld",
    "nm",
    "objcopy",
    "objdump",
    "strip",
    "ranlib",
    "c++filt",
    "dwp",
]

_CRT_OBJECTS = [
    "crt1.o",
    "crti.o",
    "crtn.o",
    "Scrt1.o",
]

_LIBS = [
    "libc.so",
    "libm.so",
    "libm.a",
    "libstdc++.so",
    "libstdc++.a",
    "libgcc_s.so",
    "libgcc_s.so.1",
]

_BUILD_CONTENT = """\
package(default_visibility = ["//visibility:public"])

filegroup(
    name = "all",
    srcs = glob(["**"]),
)

filegroup(
    name = "headers",
    srcs = glob(["include/**"]),
)

filegroup(
    name = "libs",
    srcs = glob(["lib/**"]),
)

filegroup(
    name = "binutils",
    srcs = glob(["bin/*"]),
)
"""

def _find_host_gcc_version(repository_ctx):
    """Detect the host GCC major version."""
    result = repository_ctx.execute(["gcc", "-dumpversion"])
    if result.return_code != 0:
        fail("Cannot detect host GCC version: " + result.stderr)
    return result.stdout.strip().split(".")[0]

def _resolve_symlink(repository_ctx, path):
    """Resolve a path through symlinks to get the real file."""
    result = repository_ctx.execute(["readlink", "-f", str(path)])
    if result.return_code != 0:
        return path
    return result.stdout.strip()

def _copy_file(repository_ctx, src, dst):
    """Copy a single file, resolving symlinks."""
    real_src = _resolve_symlink(repository_ctx, src)
    result = repository_ctx.execute(["cp", "-L", real_src, dst])
    if result.return_code != 0:
        # Non-fatal: some libs may not exist on all systems
        return False
    return True

def _sysroot_impl(repository_ctx):
    gcc_ver = _find_host_gcc_version(repository_ctx)

    # --- Headers: symlink /usr/include ---
    repository_ctx.symlink("/usr/include", "include")

    # --- Libraries ---
    repository_ctx.execute(["mkdir", "-p", "lib"])

    # Multiarch lib dir (Debian/Ubuntu)
    multiarch_lib = "/usr/lib/x86_64-linux-gnu"
    gcc_lib = "/usr/lib/gcc/x86_64-linux-gnu/" + gcc_ver

    # CRT objects (from multiarch dir)
    for obj in _CRT_OBJECTS:
        _copy_file(repository_ctx, multiarch_lib + "/" + obj, "lib/" + obj)

    # System libraries
    for lib in _LIBS:
        # Try multiarch first, then gcc lib dir
        if not _copy_file(repository_ctx, multiarch_lib + "/" + lib, "lib/" + lib):
            _copy_file(repository_ctx, gcc_lib + "/" + lib, "lib/" + lib)

    # libgcc.a and libgcc_eh.a from GCC lib dir
    _copy_file(repository_ctx, gcc_lib + "/libgcc.a", "lib/libgcc.a")
    _copy_file(repository_ctx, gcc_lib + "/libgcc_eh.a", "lib/libgcc_eh.a")

    # --- Binutils ---
    repository_ctx.execute(["mkdir", "-p", "bin"])
    for tool in _BINUTILS:
        src = "/usr/bin/" + tool
        _copy_file(repository_ctx, src, "bin/" + tool)
        repository_ctx.execute(["chmod", "+x", "bin/" + tool])

    # --- BUILD file ---
    repository_ctx.file("BUILD.bazel", _BUILD_CONTENT)

    # --- Record detected gcc version for toolchain config ---
    repository_ctx.file("gcc_version.txt", gcc_ver + "\n")

sysroot = repository_rule(
    implementation = _sysroot_impl,
    local = True,
    doc = "Captures host system headers, libraries, and binutils for hermetic cross-stage builds.",
)
