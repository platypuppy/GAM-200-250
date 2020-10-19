cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(executeTests ObjectDeSerialization_unit_test.cpp UnitTestClasses/DSObject.cpp ObjectDeSerialization.cpp UnitTestClasses/Object1.cpp)
target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread)

