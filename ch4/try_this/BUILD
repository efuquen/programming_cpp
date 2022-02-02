cc_binary(
    name = "currency_converter",
    srcs = ["currency_converter.cpp"],
    linkstatic = True,
    deps = [
        "//:stdlib",
        "@boost//:algorithm",
        "@com_github_nlohmann_json//:json",
        "@com_github_poco//:poco-core",
        "@com_github_poco//:poco-net",
    ],
)

cc_binary(
    name = "censor",
    srcs = ["censor.cpp"],
)
