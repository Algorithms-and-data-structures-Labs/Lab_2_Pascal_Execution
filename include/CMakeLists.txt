file(GLOB_RECURSE list_headers list/*.h list/*.hpp)
set(LIST_HEADERS "${list_headers}" PARENT_SCOPE)

file(GLOB_RECURSE stack_headers stack/*.h stack/*.hpp)
set(STACK_HEADERS "${stack_headers}" PARENT_SCOPE)

file(GLOB_RECURSE table_headers table/*.h table/*.hpp)
set(TABLE_HEADERS "${table_headers}" PARENT_SCOPE)

file(GLOB_RECURSE postfix_headers postfix/*.h postfix/*.hpp)
set(POSTFIX_HEADERS "${postfix_headers}" PARENT_SCOPE)

file(GLOB_RECURSE hlist_headers HierarchicalList/*.h HierarchicalList/*.hpp)
set(HLIST_HEADERS "${hlist_headers}" PARENT_SCOPE)

file(GLOB_RECURSE binheap_headers BinHeap/*.h BinHeap/*.hpp)
set(BINHEAP_HEADERS "${binheap_headers}" PARENT_SCOPE)