cmake_minimum_required(VERSION 3.20)
project(Final-project-tests)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
add_subdirectory(googletest)

add_executable(runRoomTests
  test/roomTests.cpp
  src/map.cpp
  src/room.cpp
)

target_link_libraries(runRoomTests gmock gtest gtest_main)