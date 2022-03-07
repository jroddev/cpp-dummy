cmake_minimum_required(VERSION 3.17)
include(FetchContent)
set(CMAKE_CXX_STANDARD 17)

project(cpp_dummy
        VERSION 0.1.0)

add_library(cpp_dummy
        include/dummy/dummy.h
        include/dummy/dummy-vector.h
        src/dummy-integral.cpp
        src/dummy-floating-point.cpp
        src/dummy-string.cpp)
target_include_directories(cpp_dummy
        PUBLIC
        include)

option(CPP_DUMMY_TESTS "" ON)

if(CPP_DUMMY_TESTS)
    FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG        release-1.11.0
    )
    FetchContent_MakeAvailable(googletest)
    add_executable(cpp_dummy_test
            test/test-main.cpp
            test/dummy-string.test.cpp
            test/dummy-integral.test.cpp
            test/dummy-floating-point.test.cpp
            test/dummy-user-defined.cpp
            test/dummy-user-defined.h
            test/dummy-user-defined.test.cpp
            test/dummy-vector.test.cpp)
    target_include_directories(cpp_dummy_test
            PRIVATE
            ${googletest_SOURCE_DIR}/googletest/include)
    target_link_libraries(cpp_dummy_test cpp_dummy gtest)
endif()