file(GLOB_RECURSE postfix_src *.cpp)
add_library(postfix_lib STATIC "${POSTFIX_HEADERS}" "${postfix_src}")
