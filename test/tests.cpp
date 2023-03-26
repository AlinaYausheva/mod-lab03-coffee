// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

using namespace std;

TEST(test1, waitTest) {
  string menu[] = { "Tea", "Milk", "Americano", "Espresso",
                   "Latte", "Cappuccino", "Hot chocolate" };
  int prices[] = { 3, 2, 4, 3, 4, 5, 3 };
  Automata automat(menu, prices);
  EXPECT_EQ(automat.getState(), Automata::OFF);
}

TEST(test2, waitTest) {
  string menu[] = { "Tea", "Milk", "Americano", "Espresso",
                   "Latte", "Cappuccino", "Hot chocolate" };
  int prices[] = { 3, 2, 4, 3, 4, 5, 3 };
  Automata automat(menu, prices);
  automat.on();
  EXPECT_EQ(automat.getState(), Automata::WAIT);
}

TEST(test3, AcceptTest) {
  string menu[] = { "Tea", "Milk", "Americano", "Espresso",
                   "Latte", "Cappuccino", "Hot chocolate" };
  int prices[] = { 3, 2, 4, 3, 4, 5, 3 };
  Automata automat(menu, prices);
  automat.on();
  automat.coin(4);
  EXPECT_EQ(automat.getState(), Automata::ACCEPT);
}

TEST(test4, AcceptTest) {
  string menu[] = { "Tea", "Milk", "Americano", "Espresso",
                   "Latte", "Cappuccino", "Hot chocolate" };
  int prices[] = { 3, 2, 4, 3, 4, 5, 3 };
  Automata automat(menu, prices);
  automat.on();
  automat.coin(1);
  automat.cancel();
  EXPECT_EQ(automat.getState(), Automata::WAIT);
}

TEST(test5, AcceptTest) {
  string menu[] = { "Tea", "Milk", "Americano", "Espresso",
                   "Latte", "Cappuccino", "Hot chocolate" };
  int prices[] = { 3, 2, 4, 3, 4, 5, 3 };
  Automata automat(menu, prices);
  automat.on();
  automat.coin(4);
  automat.coin(1);
  EXPECT_EQ(automat.getState(), Automata::ACCEPT);
}

TEST(test6, CheckTest) {
  string menu[] = { "Tea", "Milk", "Americano", "Espresso",
                   "Latte", "Cappuccino", "Hot chocolate" };
  int prices[] = { 3, 2, 4, 3, 4, 5, 3 };
  Automata automat(menu, prices);
  automat.on();
  automat.coin(1);
  automat.choice(1);
  EXPECT_EQ(automat.getState(), Automata::CHECK);
}

TEST(test7, CheckTest) {
  string menu[] = { "Tea", "Milk", "Americano", "Espresso",
                   "Latte", "Cappuccino", "Hot chocolate" };
  int prices[] = { 3, 2, 4, 3, 4, 5, 3 };
  Automata automat(menu, prices);
  automat.on();
  automat.coin(1);
  automat.coin(3);
  automat.choice(1);
  automat.check(1);
  EXPECT_EQ(automat.getState(), Automata::COOK);
}

TEST(test8, CheckTest) {
  string menu[] = { "Tea", "Milk", "Americano", "Espresso",
                   "Latte", "Cappuccino", "Hot chocolate" };
  int prices[] = { 3, 2, 4, 3, 4, 5, 3 };
  Automata automat(menu, prices);
  automat.on();
  automat.coin(1);
  automat.choice(5);
  automat.check(5);
  EXPECT_EQ(automat.getState(), Automata::ACCEPT);
}

TEST(test9, CheckTest) {
  string menu[] = { "Tea", "Milk", "Americano", "Espresso",
                   "Latte", "Cappuccino", "Hot chocolate" };
  int prices[] = { 3, 2, 4, 3, 4, 5, 3 };
  Automata automat(menu, prices);
  automat.on();
  automat.coin(1);
  automat.choice(1);
  automat.cancel();
  EXPECT_EQ(automat.getState(), Automata::WAIT);
}

TEST(test10, CookTest) {
  string menu[] = { "Tea", "Milk", "Americano", "Espresso",
                   "Latte", "Cappuccino", "Hot chocolate" };
  int prices[] = { 3, 2, 4, 3, 4, 5, 3 };
  Automata automat(menu, prices);
  automat.on();
  automat.coin(5);
  automat.choice(4);
  automat.check(4);
  automat.cook(4);
  EXPECT_EQ(automat.getState(), Automata::COOK);
}

TEST(test11, CookTest) {
  string menu[] = { "Tea", "Milk", "Americano", "Espresso",
                   "Latte", "Cappuccino", "Hot chocolate" };
  int prices[] = { 3, 2, 4, 3, 4, 5, 3 };
  Automata automat(menu, prices);
  automat.on();
  automat.coin(5);
  automat.choice(3);
  automat.check(3);
  automat.cook(3);
  automat.finish();
  EXPECT_EQ(automat.getState(), Automata::WAIT);
}
