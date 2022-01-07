cc_library(
    name = "boost",
    srcs = glob(["libboost*.so*"],
                exclude=[
                  "libboost_numpy*.so*",
                  "libboost_python*.so*",
                  "libboost_mpi_python*.so*"],),
    visibility = ["//visibility:public"],
    linkstatic = 1,
)
