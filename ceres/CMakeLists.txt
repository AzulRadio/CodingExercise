cmake_minimum_required(VERSION 2.8)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-std=c++14 -O3")


find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIRS})


add_executable(lsp lsp.cpp)
target_link_libraries(lsp ${CERES_LIBRARIES})

#static lib
#add_library(lib_name SHARED lib.cpp)

#dynamic lib
#add_library(lib_name lib.cpp)

#target_link_libraries(main lib_name)
