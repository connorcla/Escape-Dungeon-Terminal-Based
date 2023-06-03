cmake_minimum_required(VERSION 3.20)
project(Final-project-tests)

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

add_executable(runItemDatabaseTests
  test/itemDatabaseTests.cpp
  src/itemDatabase.cpp
)

add_executable(runItemTests
  test/itemTests.cpp
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

add_executable(runInventoryTests
  test/inventoryTests.cpp
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

add_executable(runInventoryScreenTests
  test/inventoryScreenTests.cpp
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

add_executable(runRoomTests
  test/roomTests.cpp
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

add_executable(runMapTests
  test/mapTest.cpp
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

add_executable(runEnemyTests
  test/enemyTests.cpp
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

target_link_libraries(runEnemyTests gmock gtest gtest_main)
target_link_libraries(runMapTests gmock gtest gtest_main)
target_link_libraries(runRoomTests gmock gtest gtest_main)
target_link_libraries(runMapTests gmock gtest gtest_main)
target_link_libraries(runItemDatabaseTests gmock gtest gtest_main)
target_link_libraries(runItemTests gmock gtest gtest_main)
target_link_libraries(runInventoryTests gmock gtest gtest_main)