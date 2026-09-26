add_library(matrix STATIC stack_matrix.cpp heap_matrix.cpp layout.cpp)
target_include_directories(matrix SYSTEM PUBLIC ${CMAKE_SOURCE_DIR}/include/matrix)
