project(math)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-fPIC")

include_directories("../..")

set(HEADERS defines.h
        mat.h)

set(SOURCES mat.cpp)

add_library(math ${HEADERS} ${SOURCES})

