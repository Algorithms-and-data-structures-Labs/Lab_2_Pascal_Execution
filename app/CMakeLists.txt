add_executable(BinHeap_queue BinHeap_queue.cpp)
target_include_directories(BinHeap_queue PRIVATE "${CMAKE_SOURCE_DIR}/include/BinHeap")

add_executable(HListApp HListApp.cpp)
target_include_directories(HListApp PRIVATE "${CMAKE_SOURCE_DIR}/include/HierarchicalList")

add_executable(ListApp ListApp.cpp)
target_include_directories(ListApp PRIVATE "${CMAKE_SOURCE_DIR}/include/List")