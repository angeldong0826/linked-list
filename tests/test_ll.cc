// Copyright (c) 2021 Angel Dong. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <cs126linkedlist/ll.h>

#include <catch2/catch.hpp>

using cs126linkedlist::LinkedList;

// Read more on SECTIONs here:
// `https://github.com/catchorg/Catch2/tree/master/docs`
// in the "Test Cases and Sections" file.

TEST_CASE("Initialize from vector",
          "[constructor][vector][size][empty][front][back]") {
  SECTION("Empty vector") {
    std::vector<int> vect;
    LinkedList<int> list(vect);

    REQUIRE(list.size() == 0);
  }

  SECTION("One element in vector") {
    LinkedList<int> list({-89});

    REQUIRE(list.size() == 1);
    REQUIRE(list.front() == -89);
    REQUIRE(list.back() == -89);
  }

  SECTION("Multiple elements in vector") {
    LinkedList<int> list({-89, 4567, 2389, 0, 1});

    REQUIRE(list.size() == 5);
    REQUIRE(list.front() == -89);
    REQUIRE(list.back() == 1);
  }
}

TEST_CASE("Copy Constructor", "[constructor][size][empty][front][back]") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("Empty list") {
    LinkedList<int> list_two(list);

    REQUIRE(list_two.size() == 0);
    REQUIRE(list_two.empty());
  }

  SECTION("List with one element") {
    LinkedList<int> list({-89});
    LinkedList<int> list_two(list);

    REQUIRE(list_two.front() == -89);
    REQUIRE(list_two.back() == -89);
    REQUIRE(list.front() == list_two.front());
    REQUIRE(list == list_two);
  }

  SECTION("List with multiple elements") {
    LinkedList<int> list({-89, 0, 5, 8});
    LinkedList<int> list_two(list);

    REQUIRE(list_two.front() == -89);
    REQUIRE(list_two.back() == 8);
    REQUIRE(list.front() == list_two.front());
    REQUIRE(list == list_two);
  }
}

TEST_CASE("Copy assignment operator",
          "[constructor][push_back][size][empty][front][back]") {
  LinkedList<int> list;

  SECTION("Empty list") {
    //    LinkedList<int> list_two = list;
    //
    //    REQUIRE(list_two.size() == 0);
    //    REQUIRE(list_two.empty());
  }

  SECTION("Lists with one element") {
    list.push_back(9);

    REQUIRE(list.size() == 1);

    LinkedList<int> list_two = list;

    REQUIRE(list_two.size() == 1);
    REQUIRE(list_two.front() == 9);
    REQUIRE(list_two.back() == 9);
  }

  SECTION("List with multiple elements") {
    list.push_back(9);
    list.push_back(56789);
    list.push_back(-9);

    REQUIRE(list.size() == 3);

    LinkedList<int> list_two = list;

    REQUIRE(list_two.size() == 3);
    REQUIRE(list_two.front() == 9);
    REQUIRE(list_two.back() == -9);
  }
}

TEST_CASE("Move constructor",
          "[constructor][push_back][size][empty][front][back]") {
  LinkedList<int> list;

  SECTION("No element in list") {
    REQUIRE(list.size() == 0);

    LinkedList<int> list_two(std::move(list));

    REQUIRE(list_two.size() == 0);
    REQUIRE(list_two.empty());
    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
  }

  SECTION("One element in list") {
    list.push_back(3);

    REQUIRE(list.size() == 1);

    LinkedList<int> list_two(std::move(list));

    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
    REQUIRE(list_two.size() == 1);
    REQUIRE(list_two.front() == 3);
    REQUIRE(list_two.back() == 3);
  }

  SECTION("Multiple elements in list") {
    list.push_back(3);
    list.push_back(0);
    list.push_back(-3);

    REQUIRE(list.size() == 3);

    LinkedList<int> list_two(std::move(list));

    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
    REQUIRE(list_two.size() == 3);
    REQUIRE(list_two.front() == 3);
    REQUIRE(list_two.back() == -3);
  }
}

TEST_CASE("Move assignment operator",
          "[constructor][push_back][size][empty][front][back]") {
  LinkedList<int> list;

  SECTION("No element in list") {
    REQUIRE(list.size() == 0);

    LinkedList<int> list_two = std::move(list);

    REQUIRE(list_two.size() == 0);
    REQUIRE(list_two.empty());
    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
  }

  SECTION("One element in list") {
    list.push_back(3);

    REQUIRE(list.size() == 1);

    LinkedList<int> list_two = std::move(list);

    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
    REQUIRE(list_two.size() == 1);
    REQUIRE(list_two.front() == 3);
    REQUIRE(list_two.back() == 3);
  }

  SECTION("Multiple elements in list") {
    list.push_back(3);
    list.push_back(0);
    list.push_back(-3);

    REQUIRE(list.size() == 3);

    LinkedList<int> list_two = std::move(list);

    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
    REQUIRE(list_two.size() == 3);
    REQUIRE(list_two.front() == 3);
    REQUIRE(list_two.back() == -3);
  }
}

TEST_CASE("Push Back", "[constructor][push_back][size][empty][front][back]") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("Push back one element") {
    list.push_back(1);

    REQUIRE(list.size() == 1);
  }

  SECTION("Push back multiple elements") {
    list.push_back(-1);
    list.push_back(10000);

    REQUIRE(list.size() == 2);
  }

  SECTION("Double Push Back Order Check") {
    list.push_back(-1);
    list.push_back(10000);

    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == -1);
    REQUIRE(list.back() == 10000);
  }
}

TEST_CASE("Push Front", "[constructor][push_front][size][empty][front][back]") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("Push front one element") {
    list.push_front(-1);

    REQUIRE(list.size() == 1);
  }

  SECTION("Push front multiple elements") {
    list.push_front(-1);
    list.push_front(10000);

    REQUIRE(list.size() == 2);
  }

  SECTION("Double Push Back Order Check") {
    list.push_front(-1);
    list.push_front(10000);

    REQUIRE(list.size() == 2);
    REQUIRE(list.back() == -1);
    REQUIRE(list.front() == 10000);
  }
}

TEST_CASE("Push Front and Back",
          "[constructor][push_front][push_back][size][empty][front][back]") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("Minimum Two elements") {
    list.push_front(-1);
    list.push_back(10000);

    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == -1);
    REQUIRE(list.back() == 10000);
  }

  SECTION("Multiple Elements") {
    list.push_front(-1);
    list.push_back(10000);
    list.push_back(32);

    REQUIRE(list.size() == 3);
    REQUIRE(list.front() == -1);
    REQUIRE(list.back() == 32);
  }
}

TEST_CASE("Size", "[constructor][size][push_front]") {
  LinkedList<int> list;

  SECTION("No element in list") { REQUIRE(list.size() == 0); }

  SECTION("One element in list") {
    list.push_front(10000);

    REQUIRE(list.size() == 1);
  }

  SECTION("Multiple elements in list") {
    list.push_front(-1);
    list.push_front(10000);
    list.push_front(100);

    REQUIRE(list.size() == 3);
  }
}

TEST_CASE("Front", "[constructor][push_front][size][empty][front]") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("No element in list") {
    try {
      list.front();
      FAIL();
    } catch (std::invalid_argument& error) {
    };

    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
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

TEST_CASE("Back", "[constructor][push_front][size][empty][back]") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("No element in list") {
    try {
      list.back();
      FAIL();
    } catch (std::invalid_argument& error) {
    };

    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
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

TEST_CASE("Call on Front and Back",
          "[constructor][push_front][push_back][size][empty][front][back]") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("Front and Back Points to Same Element when Only One Exists") {
    list.push_back(10);

    REQUIRE(list.front() == 10);
    REQUIRE(list.back() == 10);
    REQUIRE(list.front() == list.back());
  }

  SECTION("Check front and back together") {
    list.push_front(-1);
    list.push_front(10000);
    list.push_back(89);
    list.push_back(689);

    REQUIRE(list.size() == 4);
    REQUIRE(list.front() == 10000);
    REQUIRE(list.back() == 689);
  }
}

TEST_CASE("Clear", "[constructor][push_front][push_back][size][empty][clear]") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("No element in list") {
    list.clear();

    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
  }

  SECTION("One element in list") {
    list.push_front(10);
    list.clear();

    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
  }

  SECTION("Multiple elements in list") {
    list.push_front(-1);
    list.push_front(10000);
    list.push_back(89);
    list.push_back(689);

    list.clear();

    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
  }
}

TEST_CASE(
    "Pop Front",
    "[constructor][push_front][push_back][pop_front][size][empty][front]") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("No element in list") {
    try {
      list.pop_front();
      FAIL();
    } catch (std::invalid_argument& error) {
    };

    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
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
    REQUIRE(list.front() == 10000);
  }

  SECTION("Multiple pop front") {
    list.push_front(10);
    list.push_back(10000);
    list.pop_front();
    list.pop_front();

    REQUIRE(list.size() == 0);
  }
}

TEST_CASE("Pop Back",
          "[constructor][push_front][push_back][pop_back][size][empty][front]["
          "back]") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("No element in list") {
    try {
      list.pop_back();
      FAIL();
    } catch (std::invalid_argument& error) {
    };

    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
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
    REQUIRE(list.front() == 10);
    REQUIRE(list.back() == 10);
  }

  SECTION("Multiple pop back") {
    list.push_front(10);
    list.push_back(10000);
    list.pop_back();

    REQUIRE(list.front() == 10);

    list.pop_back();

    REQUIRE(list.size() == 0);
  }
}

TEST_CASE("Pop Front and Back",
          "[constructor][push_front][push_back][pop_front][pop_back][size]["
          "empty][front][back]") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("Minimum Two elements") {
    list.push_front(-1);
    list.push_back(10000);
    list.pop_back();
    list.pop_front();

    REQUIRE(list.size() == 0);
  }

  SECTION("Multiple Elements") {
    list.push_front(-1);
    list.push_back(10000);
    list.push_back(32);
    list.pop_front();
    list.pop_back();

    REQUIRE(list.size() == 1);
    REQUIRE(list.front() == 10000);
    REQUIRE(list.back() == 10000);
  }
}

TEST_CASE("Remove Nth",
          "[constructor][push_front][push_back][size][empty][front][back]["
          "RemoveNth]") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("Empty list") {
    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
  }

  SECTION("N is first element") {
    list.push_back(45);
    list.push_front(37);

    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == 37);

    list.RemoveNth(0);

    REQUIRE(list.size() == 1);
    REQUIRE(list.front() == 45);
    REQUIRE(list.back() == 45);
  }

  SECTION("N is last element") {
    list.push_back(45);
    list.push_front(37);

    REQUIRE(list.size() == 2);
    REQUIRE(list.back() == 45);

    list.RemoveNth(1);

    REQUIRE(list.size() == 1);
    REQUIRE(list.front() == 37);
    REQUIRE(list.back() == 37);
  }

  SECTION("N is an element between the head and tail of list") {
    list.push_back(45);
    list.push_front(37);
    list.push_front(896);

    REQUIRE(list.size() == 3);
    REQUIRE(list.front() == 896);
    REQUIRE(list.back() == 45);

    list.RemoveNth(1);

    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == 896);
    REQUIRE(list.back() == 45);
  }

  SECTION("Remove first and last") {
    list.push_back(45);
    list.push_front(37);
    list.push_front(896);

    REQUIRE(list.size() == 3);
    REQUIRE(list.front() == 896);
    REQUIRE(list.back() == 45);

    list.RemoveNth(0);

    REQUIRE(list.size() == 2);

    list.RemoveNth(1);

    REQUIRE(list.size() == 1);
    REQUIRE(list.front() == 37);
    REQUIRE(list.back() == 37);
  }

  SECTION("Remove first and one within range") {
    list.push_back(45);
    list.push_front(37);
    list.push_front(896);
    list.push_back(345678);

    REQUIRE(list.size() == 4);
    REQUIRE(list.front() == 896);
    REQUIRE(list.back() == 345678);

    list.RemoveNth(0);
    list.RemoveNth(2);

    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == 37);
    REQUIRE(list.back() == 45);
  }

  SECTION("Remove one within range and last") {
    list.push_back(45);
    list.push_front(37);
    list.push_front(896);
    list.push_back(345678);

    REQUIRE(list.size() == 4);
    REQUIRE(list.front() == 896);
    REQUIRE(list.back() == 345678);

    list.RemoveNth(1);
    list.RemoveNth(2);

    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == 896);
    REQUIRE(list.back() == 45);
  }

  SECTION("N out of range") {
    list.push_back(45);
    list.push_front(37);
    list.push_front(896);
    list.push_back(345678);

    REQUIRE(list.size() == 4);
    REQUIRE(list.front() == 896);
    REQUIRE(list.back() == 345678);
  }

  SECTION("Negative N") {
    list.push_back(45);
    list.push_front(37);
    list.push_front(896);
    list.push_back(345678);

    REQUIRE(list.size() == 4);
    REQUIRE(list.front() == 896);
    REQUIRE(list.back() == 345678);
  }

  SECTION("Order update after removal") {
    list.push_back(459);
    list.push_front(37);
    list.push_front(8969);
    list.push_back(345678);

    REQUIRE(list.size() == 4);
    REQUIRE(list.front() == 8969);
    REQUIRE(list.back() == 345678);

    list.RemoveNth(1);
    list.RemoveNth(2);

    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == 8969);
    REQUIRE(list.back() == 459);
  }

  SECTION("Remove multiple times") {
    list.push_back(45);
    list.push_front(37);
    list.push_front(8896);
    list.push_back(345678);

    REQUIRE(list.size() == 4);
    REQUIRE(list.front() == 8896);
    REQUIRE(list.back() == 345678);

    list.RemoveNth(1);
    list.RemoveNth(2);

    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == 8896);
    REQUIRE(list.back() == 45);
  }
}

TEST_CASE("Remove odd",
          "[constructor][push_front][push_back][size][empty][front][back]["
          "RemoveOdd]") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("Empty List") {
    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
  }

  SECTION("List with no odd index") {
    list.push_front(1);

    REQUIRE(list.size() == 1);

    list.RemoveOdd();

    REQUIRE(list.size() == 1);
    REQUIRE(list.front() == 1);
    REQUIRE(list.back() == 1);
  }

  SECTION("One odd index") {
    list.push_front(1);
    list.push_back(2);

    list.RemoveOdd();

    REQUIRE(list.size() == 1);
    REQUIRE(list.front() == 1);
    REQUIRE(list.back() == 1);
  }

  SECTION("Multiple odd indexes") {
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    list.RemoveOdd();

    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == 1);
    REQUIRE(list.back() == 3);
  }

  SECTION("Even amount of indexes") {
    list.push_back(459);
    list.push_front(37);
    list.push_front(8969);
    list.push_back(345678);

    list.RemoveOdd();

    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == 8969);
    REQUIRE(list.back() == 459);
  }

  SECTION("Odd amount of indexes") {
    list.push_back(459);
    list.push_front(37);
    list.push_front(8969);

    list.RemoveOdd();

    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == 8969);
    REQUIRE(list.back() == 459);
  }

  SECTION("Remove multiple times, test list update after removal") {
    list.push_back(459);
    list.push_front(37);
    list.push_front(8969);
    list.push_back(345678);
    list.push_back(-4567890);
    list.push_back(0);
    list.push_back(82601);

    list.RemoveOdd();

    REQUIRE(list.size() == 4);
    REQUIRE(list.front() == 8969);
    REQUIRE(list.back() == 82601);

    list.RemoveOdd();

    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == 8969);
    REQUIRE(list.back() == -4567890);

    list.RemoveOdd();

    REQUIRE(list.size() == 1);
    REQUIRE(list.front() == 8969);
    REQUIRE(list.back() == 8969);
  }
}

TEST_CASE("Equality Operator", "[constructor][push_back][size][empty]") {
  LinkedList<int> list;
  LinkedList<int> list_two_;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  REQUIRE(list_two_.size() == 0);
  REQUIRE(list_two_.empty());

  SECTION("Empty lists") { REQUIRE(list == list_two_); }

  SECTION("One empty list") {
    list_two_.push_back(2);

    REQUIRE_FALSE(list == list_two_);
  }

  SECTION("Different list sizes") {
    list.push_back(2);
    list_two_.push_back(45);
    list_two_.push_back(2);

    REQUIRE_FALSE(list == list_two_);
  }

  SECTION("Equal Lists one element") {
    list.push_back(2);
    list_two_.push_back(2);

    REQUIRE(list == list_two_);
  }

  SECTION("Equal lists multiple elements") {
    list.push_back(2);
    list.push_back(-20);
    list_two_.push_back(2);
    list_two_.push_back(-20);

    REQUIRE(list == list_two_);
  }

  SECTION("Unequal lists with one element") {
    list.push_back(-20);
    list_two_.push_back(2);

    REQUIRE_FALSE(list == list_two_);
  }

  SECTION("Unequal lists with multiple elements") {
    list.push_back(4);
    list.push_back(-20);
    list_two_.push_back(2);
    list_two_.push_back(20);

    REQUIRE_FALSE(list == list_two_);
  }

  SECTION("Unequal lists with some same elements at indexes") {
    list.push_back(2);
    list.push_back(-20);
    list_two_.push_back(2);
    list_two_.push_back(20);

    REQUIRE_FALSE(list == list_two_);
  }
}

TEST_CASE("Inequality Operator", "[constructor][push_back][size][empty]") {
  LinkedList<int> list;
  LinkedList<int> list_two_;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  REQUIRE(list_two_.size() == 0);
  REQUIRE(list_two_.empty());

  SECTION("Empty Lists") { REQUIRE_FALSE(list != list_two_); }

  SECTION("One empty list") {
    list_two_.push_back(2);

    REQUIRE(list != list_two_);
  }

  SECTION("Different list sizes") {
    list.push_back(2);
    list_two_.push_back(45);
    list_two_.push_back(2);

    REQUIRE(list != list_two_);
  }

  SECTION("Equal lists with one element") {
    list.push_back(2);
    list_two_.push_back(2);

    REQUIRE_FALSE(list != list_two_);
  }

  SECTION("Equal lists with multiple elements") {
    list.push_back(2);
    list.push_back(-20);
    list_two_.push_back(2);
    list_two_.push_back(-20);

    REQUIRE_FALSE(list != list_two_);
  }

  SECTION("Inequality with one element in lists") {
    list.push_back(2);
    list_two_.push_back(-2);

    REQUIRE(list != list_two_);
  }

  SECTION("Inequality with multiple elements in lists") {
    list.push_back(27);
    list.push_back(-20);
    list_two_.push_back(2);
    list_two_.push_back(20);

    REQUIRE(list != list_two_);
  }

  SECTION("Inequality with some equality at indexes") {
    list.push_back(27);
    list.push_back(-20);
    list_two_.push_back(27);
    list_two_.push_back(20);

    REQUIRE(list != list_two_);
  }
}

TEST_CASE("Print operator", "[constructor][push_back][ostream]") {
  LinkedList<int> list;

  SECTION("Empty list") {
    std::stringstream ss;
    ss << list;

    REQUIRE(ss.str() == "");
  }

  SECTION("One element") {
    list.push_back(27);

    std::stringstream ss;
    ss << list;

    REQUIRE(ss.str() == "27");
  }

  SECTION("Multiple elements") {
    list.push_back(27);
    list.push_back(2);
    list.push_back(-20);

    std::stringstream ss;
    ss << list;

    REQUIRE(ss.str() == "27, 2, -20");
  }

  SECTION("List with repeating elements") {
    list.push_back(27);
    list.push_back(2);
    list.push_back(-20);
    list.push_back(2);
    list.push_back(-20);

    std::stringstream ss;
    ss << list;

    REQUIRE(ss.str() == "27, 2, -20, 2, -20");
  }

  SECTION("Extra comma") {
    list.push_back(27);
    list.push_back(2);
    list.push_back(-20);

    std::stringstream ss;
    ss << list;

    REQUIRE_FALSE(ss.str() == "27, 2, -20,");
  }

  SECTION("Missing comma") {
    list.push_back(27);
    list.push_back(2);
    list.push_back(-20);

    std::stringstream ss;
    ss << list;

    REQUIRE_FALSE(ss.str() == "27, 2 -20");
  }

  SECTION("Extra space") {
    list.push_back(27);
    list.push_back(2);
    list.push_back(-20);

    std::stringstream ss;
    ss << list;

    REQUIRE_FALSE(ss.str() == "27, 2,  -20");
  }

  SECTION("No space") {
    list.push_back(27);
    list.push_back(2);
    list.push_back(-20);

    std::stringstream ss;
    ss << list;

    REQUIRE_FALSE(ss.str() == "27,2,-20");
  }
}

TEST_CASE("Iterator", "[constructor][push_back][iterator][begin][end]") {
  LinkedList<int> list;
  LinkedList<int>::iterator iterator;

  SECTION("Begin") {
    list.push_back(27);
    list.push_back(2);
    list.push_back(-20);

    iterator = list.begin();

    REQUIRE(*iterator == 27);
  }

  /// TODO
  SECTION("End") {
    list.push_back(27);
    list.push_back(2);
    list.push_back(-20);

    iterator = list.end();
  }

  SECTION("Operator++") {
    list.push_back(27);
    list.push_back(2);
    list.push_back(-20);

    iterator = list.begin();
    ++iterator;

    REQUIRE(*iterator == 2);
  }

  SECTION("Incorrect operator++") {
    list.push_back(27);
    list.push_back(2);
    list.push_back(-20);

    iterator = list.begin();
    ++iterator;

    REQUIRE_FALSE(*iterator == -20);
  }

  SECTION("Operator !=") {
    list.push_back(27);
    list.push_back(2);
    list.push_back(-20);

    iterator = list.begin();
    ++iterator;

    REQUIRE(*iterator != -20);
  }

  SECTION("Incorrect operator !=") {
    list.push_back(27);
    list.push_back(2);
    list.push_back(-20);

    iterator = list.begin();
    ++iterator;

    REQUIRE_FALSE(*iterator != 2);
  }

  SECTION("Operator *") {
    list.push_back(27);
    list.push_back(2);

    iterator = list.begin();

    REQUIRE(*iterator == 27);
  }

  SECTION("Incorrect operator *") {
    list.push_back(27);
    list.push_back(2);

    iterator = list.begin();

    REQUIRE_FALSE(*iterator == 2);
    REQUIRE(*iterator == 27);
  }
}

TEST_CASE("Const Iterator",
          "[constructor][push_back][const_iterator][begin][end]") {
  const LinkedList<int> list({37, 3, -30});
  LinkedList<int>::const_iterator iterator;

  SECTION("Begin") {
    iterator = list.begin();

    REQUIRE(*iterator == 37);
  }

  /// TODO
  SECTION("End") {
    const LinkedList<int> list({37, 3, -30});
    LinkedList<int>::const_iterator iterator;

    iterator = list.end();
  }

  SECTION("Operator++") {
    const LinkedList<int> list({37, 3, -30});
    LinkedList<int>::const_iterator iterator;

    iterator = list.begin();
    ++iterator;

    REQUIRE(*iterator == 3);
  }

  SECTION("Incorrect operator++") {
    const LinkedList<int> list({37, 3, -30});
    LinkedList<int>::const_iterator iterator;

    iterator = list.begin();
    ++iterator;

    REQUIRE_FALSE(*iterator == -30);
  }

  SECTION("Operator !=") {
    const LinkedList<int> list({37, 3, -30});
    LinkedList<int>::const_iterator iterator;

    iterator = list.begin();
    ++iterator;

    REQUIRE(*iterator != -30);
  }

  SECTION("Incorrect operator !=") {
    const LinkedList<int> list({37, 3, -30});
    LinkedList<int>::const_iterator iterator;

    iterator = list.begin();
    ++iterator;

    REQUIRE_FALSE(*iterator != 3);
  }

  SECTION("Operator *") {
    const LinkedList<int> list({37, 3});
    LinkedList<int>::const_iterator iterator;

    iterator = list.begin();

    REQUIRE(*iterator == 37);
  }

  SECTION("Incorrect operator *") {
    const LinkedList<int> list({37, 3});
    LinkedList<int>::const_iterator iterator;

    iterator = list.begin();

    REQUIRE_FALSE(*iterator == 3);
    REQUIRE(*iterator == 37);
  }
}

TEST_CASE("Different element types",
          "[constructor][push_front][push_back][size][empty][front][back]["
          "RemoveOdd][RemoveNth][pop_front][pop_back][clear]") {
  SECTION("string") {
    LinkedList<std::string> list;

    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());

    list.push_back("hi");
    list.push_front("bye");
    list.push_front("lol");
    list.push_back("yikes");

    REQUIRE(list.size() == 4);
    REQUIRE(list.front() == "lol");
    REQUIRE(list.back() == "yikes");

    list.RemoveOdd();

    REQUIRE(list.size() == 2);

    list.RemoveNth(0);

    REQUIRE(list.front() == "hi");

    list.push_back("hi again");

    REQUIRE(list.size() == 2);

    list.pop_back();

    REQUIRE(list.size() == 1);

    list.clear();

    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
  }

  SECTION("char") {
    LinkedList<char> list;

    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());

    list.push_back('a');
    list.push_front('b');
    list.push_front('c');
    list.push_back('d');

    REQUIRE(list.size() == 4);
    REQUIRE(list.front() == 'c');
    REQUIRE(list.back() == 'd');

    list.RemoveOdd();

    REQUIRE(list.size() == 2);

    list.RemoveNth(0);

    REQUIRE(list.front() == 'a');

    list.push_back('e');

    REQUIRE(list.size() == 2);

    list.pop_back();

    REQUIRE(list.size() == 1);

    list.clear();

    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
  }

  SECTION("double") {
    LinkedList<double> list;

    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());

    list.push_back(1.0);
    list.push_front(2.0);
    list.push_front(3.0);
    list.push_back(4.0);

    REQUIRE(list.size() == 4);
    REQUIRE(list.front() == 3.0);
    REQUIRE(list.back() == 4.0);

    list.RemoveOdd();

    REQUIRE(list.size() == 2);

    list.RemoveNth(0);

    REQUIRE(list.front() == 1.0);

    list.push_back(5.0);

    REQUIRE(list.size() == 2);

    list.pop_back();

    REQUIRE(list.size() == 1);

    list.clear();

    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
  }

  SECTION("size_t") {
    LinkedList<char> list;

    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());

    list.push_back(1);
    list.push_front(2);
    list.push_front(3);
    list.push_back(4);

    REQUIRE(list.size() == 4);
    REQUIRE(list.front() == 3);
    REQUIRE(list.back() == 4);

    list.RemoveOdd();

    REQUIRE(list.size() == 2);

    list.RemoveNth(0);

    REQUIRE(list.front() == 1);

    list.push_back(5);

    REQUIRE(list.size() == 2);

    list.pop_back();

    REQUIRE(list.size() == 1);

    list.clear();

    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
  }
}