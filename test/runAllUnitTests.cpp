#include "gtest/gtest.h"

#include "enemyTests.h"
#include "inventoryTests.h"
#include "itemDatabaseTests.h"
#include "itemTests.h"
#include "mapTests.h"
#include "roomTests.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}