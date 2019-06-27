project(math)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-fPIC")

include_directories("../..")

set(HEADERS defines.h
        mat.h)

set(SOURCES mat.cpp)

project(test_matrix)
add_executable(test_matrix  test_matrix.cpp ${HEADERS} ${SOURCES})

add_library(math ${HEADERS} ${SOURCES})
