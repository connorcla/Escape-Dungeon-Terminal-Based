cmake_minimum_required(VERSION 3.20)
project(Final-project-tests)

set(CMAKE_CXX_FLAGS --coverage)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

add_subdirectory(googletest)

add_executable(runMain
  main.cpp
  src/screenManager.cpp
  src/itemDatabase.cpp
  src/item.cpp
  src/inventory.cpp
  src/weapon.cpp
  src/usable.cpp
  src/equip.cpp 
  src/map.cpp
  src/room.cpp
  src/entity.cpp
  src/player.cpp
  src/enemy.cpp
  src/witch.cpp
  src/spider.cpp
  src/golem.cpp
  src/skeleton.cpp
  src/boss.cpp
)

add_executable(runAllTests
  test/runAllUnitTests.cpp
  src/itemDatabase.cpp
  src/item.cpp
  src/inventory.cpp
  src/weapon.cpp
  src/usable.cpp
  src/equip.cpp 
  src/map.cpp
  src/room.cpp
  src/entity.cpp
  src/player.cpp
  src/enemy.cpp
  src/witch.cpp
  src/spider.cpp
  src/golem.cpp
  src/skeleton.cpp
  src/boss.cpp
)

target_link_libraries(runAllTests gmock gtest gtest_main)
