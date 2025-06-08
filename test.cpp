
// shiraba01@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.hpp"
#include "AscendingOrderIterator.hpp"
#include "DescendingOrderIterator.hpp"
#include "SideCrossOrderIterator.hpp"
#include "ReverseOrderIterator.hpp"
#include "OrderIterator.hpp"
#include "MiddleOutOrderIterator.hpp"

using namespace assignment4;

TEST_CASE("Test MyContainer::add and size") {
    MyContainer<int> c;
    CHECK(c.getData().size() == 0);
    c.add(5);
    c.add(10);
    CHECK(c.getData().size() == 2);
}

TEST_CASE("Test MyContainer::remove existing and non-existing value") {
    MyContainer<int> c;
    c.add(1);
    c.add(2);
    c.add(1);
    c.remove(1);
    CHECK(c.getData().size() == 1);
    CHECK_THROWS_AS(c.remove(3), std::runtime_error);
}

TEST_CASE("Test MyContainer::operator<< output format") {
    MyContainer<int> c;
    c.add(1);
    c.add(2);
    std::ostringstream oss;
    oss << c;
    CHECK(oss.str() == "[1, 2]");
}

TEST_CASE("AscendingOrderIterator - basic and edge cases") {
    MyContainer<int> c;
    c.add(5);
    c.add(1);
    c.add(3);
    std::vector<int> result;
    for (auto it = AscendingOrderIterator<int>::begin(c); it != AscendingOrderIterator<int>::end(c); ++it) {
        result.push_back(*it);
    }
    CHECK(result == std::vector<int>({1, 3, 5}));
}

TEST_CASE("DescendingOrderIterator - basic and edge cases") {
    MyContainer<int> c;
    c.add(2);
    c.add(10);
    c.add(7);
    std::vector<int> result;
    for (auto it = DescendingOrderIterator<int>::begin(c); it != DescendingOrderIterator<int>::end(c); ++it) {
        result.push_back(*it);
    }
    CHECK(result == std::vector<int>({10, 7, 2}));
}

TEST_CASE("ReverseOrderIterator - basic and edge cases") {
    MyContainer<int> c;
    c.add(3);
    c.add(6);
    c.add(9);
    std::vector<int> result;
    for (auto it = ReverseOrderIterator<int>::begin(c); it != ReverseOrderIterator<int>::end(c); ++it) {
        result.push_back(*it);
    }
    CHECK(result == std::vector<int>({9, 6, 3}));
}

TEST_CASE("OrderIterator - maintains insertion order") {
    MyContainer<int> c;
    c.add(4);
    c.add(5);
    c.add(6);
    std::vector<int> result;
    for (auto it = OrderIterator<int>::begin(c); it != OrderIterator<int>::end(c); ++it) {
        result.push_back(*it);
    }
    CHECK(result == std::vector<int>({4, 5, 6}));
}

TEST_CASE("SideCrossOrderIterator - zigzag pattern") {
    MyContainer<int> c;
    c.add(7);
    c.add(1);
    c.add(15);
    c.add(2);
    c.add(6);
    std::vector<int> result;
    for (auto it = SideCrossOrderIterator<int>::begin(c); it != SideCrossOrderIterator<int>::end(c); ++it) {
        result.push_back(*it);
    }
    CHECK(result == std::vector<int>({1, 15, 2, 7, 6}));
}

TEST_CASE("MiddleOutOrderIterator - center to outside") {
    MyContainer<int> c;
    c.add(10);
    c.add(20);
    c.add(30);
    c.add(40);
    c.add(50);
    std::vector<int> result;
    for (auto it = MiddleOutOrderIterator<int>::begin(c); it != MiddleOutOrderIterator<int>::end(c); ++it) {
        result.push_back(*it);
    }
    CHECK(result == std::vector<int>({30, 40, 20, 50, 10}));
}

TEST_CASE("Edge case: empty container") {
    MyContainer<int> c;
    CHECK(c.getData().empty());

    std::vector<int> result;
    for (auto it = AscendingOrderIterator<int>::begin(c); it != AscendingOrderIterator<int>::end(c); ++it) {
        result.push_back(*it);
    }
    CHECK(result.empty());
}

// Additional tests for MyContainer with different data types and edge cases

// Test MyContainer with std::string
TEST_CASE("MyContainer<std::string> - add, remove, and AscendingOrderIterator") {
    MyContainer<std::string> c;
    c.add("banana");
    c.add("apple");
    c.add("cherry");

    // Test ascending order for strings
    std::vector<std::string> result;
    for (auto it = AscendingOrderIterator<std::string>::begin(c); it != AscendingOrderIterator<std::string>::end(c); ++it) {
        result.push_back(*it);
    }
    CHECK(result == std::vector<std::string>({"apple", "banana", "cherry"}));

    // Test removal
    c.remove("banana");
    CHECK(c.getData().size() == 2);
    CHECK_THROWS_AS(c.remove("mango"), std::runtime_error);
}

// Test MyContainer with double values
TEST_CASE("MyContainer<double> - DescendingOrderIterator") {
    MyContainer<double> c;
    c.add(3.14);
    c.add(2.71);
    c.add(1.618);

    std::vector<double> result;
    for (auto it = DescendingOrderIterator<double>::begin(c); it != DescendingOrderIterator<double>::end(c); ++it) {
        result.push_back(*it);
    }
    CHECK(result == std::vector<double>({3.14, 2.71, 1.618}));
}

// Custom struct for testing
struct Point {
    int x;
    bool operator<(const Point& other) const { return x < other.x; }
    bool operator>(const Point& other) const { return x > other.x; }
    bool operator==(const Point& other) const { return x == other.x; }
};

// Required for printing Points in test output
std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << "{" << p.x << "}";
}

TEST_CASE("MyContainer::size basic behavior") {
    MyContainer<int> c;
    CHECK(c.size() == 0);
    c.add(1);
    CHECK(c.size() == 1);
    c.add(2);
    CHECK(c.size() == 2);
    c.remove(1);
    CHECK(c.size() == 1);
    c.remove(2);
    CHECK(c.size() == 0);
}



TEST_CASE("MyContainer::remove throws on non-existent element") {
    MyContainer<int> c;
    CHECK_THROWS_AS(c.remove(5), std::runtime_error);
    c.add(1);
    CHECK_THROWS_AS(c.remove(2), std::runtime_error);
}

TEST_CASE("MyContainer edge case: very large number of elements") {
    MyContainer<int> c;
    for (int i = 0; i < 1000; ++i) {
        c.add(i);
    }
    CHECK(c.size() == 1000);
    for (int i = 0; i < 500; ++i) {
        c.remove(i);
    }
    CHECK(c.size() == 500);
}
