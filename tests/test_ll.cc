// Copyright (c) 2021 Angel Dong. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <cs126linkedlist/ll.h>


using cs126linkedlist::LinkedList;

// Read more on SECTIONs here:
// `https://github.com/catchorg/Catch2/tree/master/docs`
// in the "Test Cases and Sections" file.
TEST_CASE("Push Back", "[constructor][push_back][size][empty]") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("Push back one element") {
    list.push_back(1);
    REQUIRE(list.size() == 1);
  }

  SECTION("Push back two elements") {
    list.push_back(-1);
    list.push_back(10000);
    REQUIRE(list.size() == 2);
  }
}

TEST_CASE("Push Front") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("Push front one element") {
    list.push_front(-1);
    REQUIRE(list.size() == 1);
  }

  SECTION("Push front two elements") {
    list.push_front(-1);
    list.push_front(10000);
    REQUIRE(list.size() == 2);
  }
}

TEST_CASE("Size") {
  LinkedList<int> list;

  SECTION("No element in list") {
    REQUIRE(list.size() == 0);
  }

  SECTION("One element in list") {
    list.push_front(10000);
    REQUIRE(list.size() == 1);
  }

  SECTION("Multiple elements in list") {
    list.push_front(-1);
    list.push_front(10000);
    REQUIRE(list.size() == 2);
  }
}

TEST_CASE("Front") {
  LinkedList<int> list;
  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("No element in list") {
  }

  SECTION("One element in list") {
    list.push_front(10000);
    REQUIRE(list.front() == 10000);
  }

  SECTION("Multiple elements in list") {
    list.push_front(-1);
    list.push_front(10000);
    REQUIRE(list.front() == 10000);
  }
}

TEST_CASE("Back") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("No element in list") {
  }

  SECTION("One element in list") {
    list.push_front(10000);
    REQUIRE(list.back() == 10000);
  }

  SECTION("Multiple elements in list") {
    list.push_front(-1);
    list.push_front(10000);
    REQUIRE(list.back() == -1);
  }
}

TEST_CASE("Clear") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("No element in list") {
  }

  SECTION("One element in list") {
    list.push_front(10);
    list.clear();
    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
  }

  SECTION("Multiple elements in list") {

  }
}

TEST_CASE("Pop Front") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("No element in list") {
  }

  SECTION("One element in list") {
    list.push_front(10);
    list.pop_front();
    REQUIRE(list.size() == 0);
  }

  SECTION("Multiple elements in list") {
    list.push_front(10);
    list.push_back(10000);
    list.pop_front();
    REQUIRE(list.size() == 1);
    REQUIRE(list.front() ==  10000);
  }
}

TEST_CASE("Pop Back") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("No element in list") {
  }

  SECTION("One element in list") {
    list.push_back(10);
    list.pop_back();
    REQUIRE(list.size() == 0);
  }

  SECTION("Multiple elements in list") {
    list.push_front(10);
    list.push_back(10000);
    list.pop_back();
    REQUIRE(list.size() == 1);
  }
}
