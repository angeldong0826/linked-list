// Copyright (c) 2021 Angel Dong. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <cs126linkedlist/ll.h>

using cs126linkedlist::LinkedList;

// Read more on SECTIONs here:
// `https://github.com/catchorg/Catch2/tree/master/docs`
// in the "Test Cases and Sections" file.

TEST_CASE("Initialize from vector") {
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

TEST_CASE("Copy Constructor") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("Empty list") {

  }

  SECTION("List with one element") {

  }

  SECTION("List with multiple elements") {

  }
}

TEST_CASE("Destructor") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("Empty list") {

  }

  SECTION("List with one element") {

  }

  SECTION("List with multiple elements") {

  }
}

TEST_CASE("Push Back", "[constructor][push_back][size][empty]") {
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

TEST_CASE("Push Front") {
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

TEST_CASE("Push Front and Back") {
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
    list.push_front(100);

    REQUIRE(list.size() == 3);
  }
}

TEST_CASE("Front") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("No element in list") {
    try {
      list.front();
      FAIL();
    }
    catch(std::invalid_argument& error){
    };
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
    try {
      list.back();
      FAIL();
    }
    catch(std::invalid_argument& error){
    };
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

TEST_CASE("Call on Front and Back") {
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

TEST_CASE("Clear") {
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
  }
}

TEST_CASE("Pop Front") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("No element in list") {
    try {
      list.pop_front();
      FAIL();
    }
    catch(std::invalid_argument& error){
    };
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

  SECTION("Multiple pop front") {
    list.push_front(10);
    list.push_back(10000);
    list.pop_front();
    list.pop_front();

    REQUIRE(list.size() == 0);
  }
}

TEST_CASE("Pop Back") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("No element in list") {
    try {
      list.pop_back();
      FAIL();
    }
    catch(std::invalid_argument& error){
    };
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

TEST_CASE("Pop Front and Back") {
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

TEST_CASE("Remove Nth") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("Empty list") {
    try {
      list.RemoveNth(0);
      FAIL();
    }
    catch(std::invalid_argument& error){
    };
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

    try {
      list.RemoveNth(4);
      FAIL();
    }
    catch(std::invalid_argument& error){
    };
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

TEST_CASE("Remove odd") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("Empty List") {
    try {
      list.RemoveOdd();
      FAIL();
    }
    catch(std::invalid_argument& error){
    };
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

TEST_CASE("Equality Operator") {
  LinkedList<int> list;
  LinkedList<int> list_two_;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  REQUIRE(list_two_.size() == 0);
  REQUIRE(list_two_.empty());

  SECTION("Empty lists") {
    REQUIRE(list == list_two_);
  }

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

TEST_CASE("Inequality Operator") {
  LinkedList<int> list;
  LinkedList<int> list_two_;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  REQUIRE(list_two_.size() == 0);
  REQUIRE(list_two_.empty());

  SECTION("Empty Lists") {
    REQUIRE_FALSE(list != list_two_);
  }

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

TEST_CASE("Iterator") {

}

TEST_CASE("Const Iterator") {

}