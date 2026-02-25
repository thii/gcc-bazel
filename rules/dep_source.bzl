"Repository rule to download a dependency and overlay pre-generated files."

def _dep_source_impl(repository_ctx):
    repository_ctx.report_progress("Downloading %s..." % repository_ctx.name)
    repository_ctx.download_and_extract(
        url = repository_ctx.attr.urls,
        sha256 = repository_ctx.attr.sha256,
        stripPrefix = repository_ctx.attr.strip_prefix,
    )

    # Copy pre-generated files into the source tree
    # generated_files is label_keyed_string_dict: {source_label: dest_path}
    for src_label, dst in repository_ctx.attr.generated_files.items():
        content = repository_ctx.read(src_label)
        repository_ctx.file(dst, content)

    # Copy files within the repo (e.g. place public headers in include/)
    for src, dst in repository_ctx.attr.copy_files.items():
        content = repository_ctx.read(src)
        repository_ctx.file(dst, content)

    # Write the BUILD file
    build_content = repository_ctx.read(repository_ctx.attr.build_file)
    repository_ctx.file("BUILD.bazel", build_content)

dep_source = repository_rule(
    implementation = _dep_source_impl,
    attrs = {
        "urls": attr.string_list(mandatory = True, doc = "Mirror URLs for the source tarball."),
        "sha256": attr.string(default = "", doc = "Expected SHA-256 hash of the tarball."),
        "strip_prefix": attr.string(default = "", doc = "Directory prefix to strip from the archive."),
        "build_file": attr.label(mandatory = True, doc = "Label of the BUILD file to overlay onto the extracted source."),
        "generated_files": attr.label_keyed_string_dict(default = {}, doc = "Map of source label -> dest path for pre-generated files to copy in."),
        "copy_files": attr.string_dict(default = {}, doc = "Map of src path -> dest path for files to copy within the extracted tree."),
    },
    doc = "Downloads a source archive and overlays pre-generated config files.",
)
