package(default_visibility = ["//visibility:public"])

load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "poco-net",
    srcs = glob(["Net/src/*.cc", "Net/src/*.cpp"]),
    hdrs = glob(["Net/include/Poco/Net/*.h"]),
    strip_include_prefix = "Net/include/",
    deps = [":poco-core"],
)

cc_library(
    name = "poco-util",
    srcs = glob(["Util/src/*.cpp"],
        exclude = ["Util/src/Win*"]
    ),
    hdrs = glob(["Util/include/Poco/Util/*.h"]),
    strip_include_prefix = "Util/include/",
    deps = [":poco-core"],
)

cc_library(
    name = "poco-crypto",
    srcs = glob(["Crypto/src/*.cpp"]),
    hdrs = glob(["Crypto/include/Poco/Crypto/*.h"]),
    strip_include_prefix = "Crypto/include/",
    deps = [":poco-core"],
)

cc_library(
    name = "poco-net-openssl",
    srcs = glob(["NetSSL_OpenSSL/src/*.cpp"]),
    hdrs = glob(["NetSSL_OpenSSL/include/Poco/Net/*.h"]),
    strip_include_prefix = "NetSSL_OpenSSL/include/",
    deps = [":poco-net", ":poco-crypto", ":poco-util"],
)

cc_library(
    name = "poco-core",
    srcs = glob(
        ["Foundation/src/*.cc", "Foundation/src/*.cpp", "Foundation/src/*.h", "Foundation/src/*.c"],
        exclude = [
            "Foundation/src/*WIN32*", "Foundation/src/*WINCE.cpp", "Foundation/src/*VX.cpp",
            "Foundation/src/*SUN.cpp", "Foundation/src/*DEC.cpp", "Foundation/src/*_UNIX.cpp",
            "Foundation/src/*POSIX.cpp","Foundation/src/FPEnvironment_C99.cpp",
            "Foundation/src/WindowsConsoleChannel.cpp", "Foundation/src/*HPUX.cpp",
            "Foundation/src/EventLogChannel.cpp"]),
    copts = ["-Iexternal/com_github_poco/Foundation/src", "-Iexternal/com_github_poco/Foundation/include"],
    hdrs = glob(["Foundation/include/Poco/*.h", "Foundation/include/Poco/Dynamic/*.h"],
                exclude=[]),
    textual_hdrs = glob([
        "Foundation/src/*_UNIX.cpp", "Foundation/src/*POSIX.cpp","Foundation/src/FPEnvironment_C99.cpp",
        "Foundation/src/*.cc", "Foundation/src/LogFile_STD.cpp"]),
    local_defines = ["POCO_NO_WINDOWS_H"],
    strip_include_prefix = "Foundation/include/",
)