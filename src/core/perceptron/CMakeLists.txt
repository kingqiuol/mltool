project(perceptron)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-fPIC")

include_directories(../../..)
include_directories(..)
include_directories(../../math)

set(HEADERS initialization.h
        learning_policies.h)

set(SOURCE perceptron.cpp)

add_library(perceptron ${HEADERS} ${SOURCE})
target_link_libraries(perceptron math)
