project(io)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-fPIC")

include_directories(../..)

set(HEADER dataloader.h
        defines.h
        classifier_dataloader.h)

set(SOURCE classifier_dataloader.cpp)

add_library(io ${HEADERS} ${SOURCE})
#target_link_libraries(io )




