load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

_RULES_BOOST_COMMIT = "652b21e35e4eeed5579e696da0facbe8dba52b1f"

http_archive(
    name = "com_github_nelhage_rules_boost",
    sha256 = "c1b8b2adc3b4201683cf94dda7eef3fc0f4f4c0ea5caa3ed3feffe07e1fb5b15",
    strip_prefix = "rules_boost-%s" % _RULES_BOOST_COMMIT,
    urls = [
        "https://github.com/nelhage/rules_boost/archive/%s.tar.gz" % _RULES_BOOST_COMMIT,
    ],
)

load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")

boost_deps()

http_archive(
    name = "com_github_nlohmann_json",
    build_file = "json.BUILD",
    sha256 = "5daca6ca216495edf89d167f808d1d03c4a4d929cef7da5e10f135ae1540c7e4",
    strip_prefix = "json-3.10.5",
    urls = ["https://github.com/nlohmann/json/archive/v3.10.5.tar.gz"],
)

http_archive(
    name = "com_github_poco",
    build_file = "poco.BUILD",
    sha256 = "2412a5819a239ff2ee58f81033bcc39c40460d7a8b330013a687c8c0bd2b4ac0",
    strip_prefix = "poco-poco-1.11.1-release",
    urls = ["https://github.com/pocoproject/poco/archive/poco-1.11.1-release.tar.gz"],
)

http_archive(
    name = "com_google_absl",
    strip_prefix = "abseil-cpp-98eb410c93ad059f9bba1bf43f5bb916fc92a5ea",
    urls = ["https://github.com/abseil/abseil-cpp/archive/98eb410c93ad059f9bba1bf43f5bb916fc92a5ea.zip"],
)

http_archive(
    name = "rules_cc",
    strip_prefix = "rules_cc-262ebec3c2296296526740db4aefce68c80de7fa",
    urls = ["https://github.com/bazelbuild/rules_cc/archive/262ebec3c2296296526740db4aefce68c80de7fa.zip"],
)

new_local_repository(
    name = "libcurl",
    build_file = "libcurl.BUILD",
    path = "/usr/lib/x86_64-linux-gnu",
)
