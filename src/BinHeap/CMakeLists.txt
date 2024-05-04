file(GLOB_RECURSE binheap_src *.cpp)
add_library(binheap_lib STATIC "${BINHEAP_HEADERS}" "${binheap_src}")
