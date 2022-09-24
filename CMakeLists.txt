cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
project(CPLib-AlgOritHm CXX)
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    AlgOritHm_test
    test/fractionTest.cpp
    test/graphTest.cpp
    test/matrixTest.cpp
    test/stringTest.cpp
    test/ds/DSUTest.cpp
    test/ds/MonotonyStackTest.cpp
    test/ds/MonotonyQueueTest.cpp
    test/ds/SparseTableTest.cpp
    test/math/numtheoryTest.cpp
)
target_link_libraries(AlgOritHm_test gtest_main)

include(GoogleTest)
gtest_discover_tests(AlgOritHm_test)
