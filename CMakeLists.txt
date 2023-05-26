cmake_minimum_required(VERSION 3.20)
project(Final-project-tests)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
add_subdirectory(googletest)

add_executable(runMain
  main.cpp
  src/screenManager.cpp
  src/map.cpp
  src/room.cpp
  src/itemDatabase.cpp
  src/inventory.cpp
  src/item.cpp
  src/weapon.cpp
  src/equip.cpp
  src/usable.cpp

)

add_executable(runRoomTests
  test/roomTests.cpp
  src/map.cpp
  src/room.cpp
)

target_link_libraries(runRoomTests gmock gtest gtest_main)
target_link_libraries(runMain gmock gtest gtest_main)