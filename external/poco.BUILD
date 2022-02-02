package(default_visibility = ["//visibility:public"])

load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "poco-net",
    hdrs = glob(["Net/include/Poco/Net/*.h"]),
    strip_include_prefix = "Net/include/",
)

cc_library(
    name = "poco-core",
    hdrs = glob(["Foundation/include/Poco/*.h"]),
    strip_include_prefix = "Foundation/include/",
)