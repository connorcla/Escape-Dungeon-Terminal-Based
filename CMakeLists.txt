cmake_minimum_required(VERSION 3.20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
add_subdirectory(googletest)

add_executable(runOutputTests

  test/screenOutputTests.cpp
  src/screenManager.cpp
)

target_link_libraries(runOutputTests gmock gtest gtest_main)