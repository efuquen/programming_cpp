load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

new_local_repository(
    name = "libcurl",
    path = "/usr/lib/x86_64-linux-gnu",
    build_file = "libcurl.BUILD"
)

http_archive(
    name = "com_github_nlohmann_json",
    build_file = "json.BUILD",
    sha256 = "5daca6ca216495edf89d167f808d1d03c4a4d929cef7da5e10f135ae1540c7e4",
    strip_prefix = "json-3.10.5",
    urls = ["https://github.com/nlohmann/json/archive/v3.10.5.tar.gz"],
)
