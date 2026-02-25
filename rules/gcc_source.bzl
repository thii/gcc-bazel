"Repository rule to download GCC source and overlay Bazel BUILD files."

_OVERLAYS = {
    "BUILD.bazel": Label("//rules/overlay:root.BUILD"),
    "gcc/BUILD.bazel": Label("//rules/overlay:gcc.BUILD"),
    "libiberty/BUILD.bazel": Label("//rules/overlay:libiberty.BUILD"),
    "libcpp/BUILD.bazel": Label("//rules/overlay:libcpp.BUILD"),
    "libdecnumber/BUILD.bazel": Label("//rules/overlay:libdecnumber.BUILD"),
    "libbacktrace/BUILD.bazel": Label("//rules/overlay:libbacktrace.BUILD"),
    "libcody/BUILD.bazel": Label("//rules/overlay:libcody.BUILD"),
    "libgcc/BUILD.bazel": Label("//rules/overlay:libgcc.BUILD"),
}

def _gcc_source_impl(repository_ctx):
    repository_ctx.report_progress("Downloading GCC source...")
    repository_ctx.download_and_extract(
        url = repository_ctx.attr.urls,
        sha256 = repository_ctx.attr.sha256,
        stripPrefix = repository_ctx.attr.strip_prefix,
    )

    # Make configure scripts executable (GitHub archives may strip +x)
    repository_ctx.execute([
        "find",
        ".",
        "-name",
        "configure",
        "-exec",
        "chmod",
        "+x",
        "{}",
        ";",
    ])
    repository_ctx.execute([
        "find",
        ".",
        "-name",
        "*.sh",
        "-exec",
        "chmod",
        "+x",
        "{}",
        ";",
    ])

    # Overlay BUILD files
    for dst, src_label in _OVERLAYS.items():
        content = repository_ctx.read(src_label)
        repository_ctx.file(dst, content)

    # Copy gengtype pre-generated output files (skip BUILD files)
    gengtype_marker = repository_ctx.path(repository_ctx.attr._gengtype_marker)
    gengtype_dir = gengtype_marker.dirname
    result = repository_ctx.execute(["ls", str(gengtype_dir)])
    if result.return_code == 0:
        repository_ctx.execute(["mkdir", "-p", "gcc/gengtype-output"])
        for name in result.stdout.strip().split("\n"):
            if name and not name.startswith("BUILD"):
                src = str(gengtype_dir) + "/" + name
                repository_ctx.execute(["cp", src, "gcc/gengtype-output/" + name])

gcc_source = repository_rule(
    implementation = _gcc_source_impl,
    attrs = {
        "urls": attr.string_list(mandatory = True, doc = "Mirror URLs for the GCC source tarball."),
        "sha256": attr.string(default = "", doc = "Expected SHA-256 hash of the tarball."),
        "strip_prefix": attr.string(default = "", doc = "Directory prefix to strip from the archive."),
        "_gengtype_marker": attr.label(
            default = Label("//rules/gengtype-output:gtype-desc.cc"),
            doc = "Label used to locate the pre-generated gengtype output directory.",
        ),
    },
    doc = "Downloads GCC source and overlays Bazel BUILD files for building cc1.",
)
