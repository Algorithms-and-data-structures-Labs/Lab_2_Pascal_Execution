file(GLOB_RECURSE hlist_src *.cpp)
add_library(hlist_lib STATIC "${HLIST_HEADERS}" "${hlist_src}")
