cmake_minimum_required(VERSION 3.6.0)
project(pybind_eigen VERSION 0.1.0)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++14" COMPILER_SUPPORTS_CXX14)

if(COMPILER_SUPPORTS_CXX14)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
    set(CMAKE_CXX_FLAGS "-D_hypot=hypot")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++14 support. Please use a different C++ compiler.")
endif()



link_directories(${PROJECT_SOURCE_DIR}/library)
add_library(${PROJECT_NAME} SHARED ./src/cpp/pybind_eigen.cpp)

target_include_directories(${PROJECT_NAME}
                           PRIVATE
                           ${PROJECT_SOURCE_DIR}/include/python36
                           ${PROJECT_SOURCE_DIR}/include/pybind11
                           ${PROJECT_SOURCE_DIR}/include/eigen3.3.7
                           )

if(WIN32)
target_link_libraries(${PROJECT_NAME}
                      /Windows/python36
                      )
set_target_properties(${PROJECT_NAME}
                      PROPERTIES SUFFIX
                      ".pyd"
                      )
elseif(UNIX)
target_link_libraries(${PROJECT_NAME}
                      /Linux/python3.6m
                      )
set_target_properties(${PROJECT_NAME}
                      PROPERTIES SUFFIX
                      ".so"
                      )
endif()
