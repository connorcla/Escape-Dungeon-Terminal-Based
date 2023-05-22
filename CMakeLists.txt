cmake_minimum_required(VERSION 3.20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
add_subdirectory(googletest)

add_executable(runOutputTests
  test/screenOutputTests.cpp
  src/screenManager.cpp
  src/itemDatabase.cpp
  src/item.cpp
  src/inventory.cpp
  src/weapon.cpp
  src/usable.cpp
  src/equip.cpp 
)

add_executable(runItemDatabaseTests
  test/itemDatabaseTests.cpp
  src/itemDatabase.cpp
)

add_executable(runItemTests
  test/itemTests.cpp
  src/item.cpp
  src/itemDatabase.cpp
)

add_executable(runInventoryTests
  test/inventoryTests.cpp
  src/itemDatabase.cpp
  src/item.cpp
  src/inventory.cpp
  src/weapon.cpp
  src/usable.cpp
  src/equip.cpp 
)

add_executable(runInventoryScreenTests
  test/inventoryScreenTests.cpp
  src/screenManager.cpp
  src/itemDatabase.cpp
  src/item.cpp
  src/inventory.cpp
  src/weapon.cpp
  src/usable.cpp
  src/equip.cpp 
)

target_link_libraries(runItemDatabaseTests gmock gtest gtest_main)
target_link_libraries(runItemTests gmock gtest gtest_main)
target_link_libraries(runInventoryTests gmock gtest gtest_main)