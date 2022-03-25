#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"
#include <string>
using namespace ariel;
using namespace std;

TEST_CASE("Notebook initialization") {
    Notebook notebook;
}

TEST_CASE("TEST for write and read functions: good horizontal") {
    Notebook nb1;
    nb1.write(0, 0, 0, Direction::Horizontal, "notebook write function test");
    CHECK(nb1.read(0, 0, 0, Direction::Horizontal, 28) == "notebook write function test");
    nb1.write(0, 3, 0, Direction::Horizontal, "this is fun");
    CHECK(nb1.read(0, 3, 0, Direction::Horizontal, 11) == "this is fun");
    nb1.write(0, 10, 0, Direction::Horizontal, "now let's check in the middle");
    CHECK(nb1.read(0, 10, 16, Direction::Horizontal, 13) == "in the middle");
    string output;
    for (int i = 65; i < 123; i++) {
        char ch = i;
        string tmp_string(1, ch);
        nb1.write(1, 0, i - 65, Direction::Horizontal, tmp_string);
        output += i;
        CHECK(nb1.read(1, 0, 0, Direction::Horizontal, i - 64) == output);

    }
}

TEST_CASE("TEST for write and read functions: good vertical") {
    Notebook nb2;
    nb2.write(0, 0, 0, Direction::Vertical, "notebook write function test");
    CHECK(nb2.read(0, 0, 0, Direction::Vertical, 28) == "notebook write function test");
    nb2.write(0, 3, 1, Direction::Vertical, "this is fun");
    CHECK(nb2.read(0, 3, 1, Direction::Vertical, 11) == "this is fun");
    nb2.write(0, 10, 5, Direction::Vertical, "now let's check in the middle");
    CHECK(nb2.read(0, 26, 5, Direction::Vertical, 13) == "in the middle");
    string output;
    for (int i = 65; i < 123; i++) {
        char ch = i;
        string tmp_string(1, ch);
        nb2.write(1, i - 65, 0, Direction::Vertical, tmp_string);
        output += i;
        CHECK(nb2.read(1, 0, 0, Direction::Vertical, i - 64) == output);
    }
}

TEST_CASE("TEST for write and read functions: good horizontal and vertical") {
    Notebook nb3;
    nb3.write(0, 0, 0, Direction::Horizontal, "notebook write function test");
    CHECK(nb3.read(0, 0, 0, Direction::Horizontal, 28) == "notebook write function test");
    nb3.write(0, 3, 0, Direction::Vertical, "this is fun");
    CHECK(nb3.read(0, 3, 0, Direction::Vertical, 11) == "this is fun");
    nb3.write(0, 10, 2, Direction::Horizontal, "now let's check in the middle");
    CHECK(nb3.read(0, 10, 18, Direction::Horizontal, 13) == "in the middle");
    nb3.write(0, 50, 20, Direction::Vertical, "It actually works!");
    CHECK(nb3.read(0, 50, 20, Direction::Vertical, 18) == "It actually works!");
}

TEST_CASE("TEST write function:: invalid writing") {
    Notebook nb4;
    nb4.write(0, 0, 0, Direction::Horizontal, "Let's check if an error will occur if we'll write again");
    nb4.write(1, 0, 0, Direction::Vertical, "Let's check if an error will occur if we'll write again");
    for (int i = 0; i < 55; ++i) {
        CHECK_THROWS(nb4.write(0, 0, i, Direction::Horizontal, "something"));
        CHECK_THROWS(nb4.write(1, i, 0, Direction::Vertical, "something"));
    }
    CHECK_THROWS(nb4.write(2, 0, 0, Direction::Horizontal, "this sentence is going to be larger than 100 chars so we need to throw an error because of what we have been told to do"));
    CHECK_THROWS(nb4.write(2, 1, 80, Direction::Horizontal, "this sentence is going to be overload the 100 chars"));

    CHECK_THROWS(nb4.write(-1, 0, 0, Direction::Horizontal, "something"));
    CHECK_THROWS(nb4.write(0, -1, 0, Direction::Horizontal, "something"));
    CHECK_THROWS(nb4.write(0, 0, -1, Direction::Horizontal, "something"));
    CHECK_THROWS(nb4.write(0, -1, -1, Direction::Horizontal, "something"));
    CHECK_THROWS(nb4.write(-1, -1, 0, Direction::Horizontal, "something"));
    CHECK_THROWS(nb4.write(-1, 0, -1, Direction::Horizontal, "something"));
    CHECK_THROWS(nb4.write(-1, -1, -1, Direction::Horizontal, "something"));

    CHECK_THROWS(nb4.read(-1, 0, 0, Direction::Horizontal, 10));
    CHECK_THROWS(nb4.read(0, -1, 0, Direction::Horizontal, 10));
    CHECK_THROWS(nb4.read(0, 0, -1, Direction::Horizontal, 10));
    CHECK_THROWS(nb4.read(0, -1, -1, Direction::Horizontal, 10));
    CHECK_THROWS(nb4.read(-1, -1, 0, Direction::Horizontal, 10));
    CHECK_THROWS(nb4.read(-1, 0, -1, Direction::Horizontal, 10));
    CHECK_THROWS(nb4.read(-1, -1, -1, Direction::Horizontal, 10));
    CHECK_THROWS(nb4.read(-1, -1, -1, Direction::Horizontal, -1));
    CHECK_THROWS(nb4.read(0, 0, 0, Direction::Horizontal, -1));
}

TEST_CASE("erase function") {
    Notebook nb5;
    nb5.write(0, 0, 0, Direction::Horizontal, "Let's check the erase function");
    CHECK(nb5.read(0, 0, 0, Direction::Horizontal, 30) == "Let's check the erase function");
    nb5.erase(0, 0, 0, Direction::Horizontal, 20);
    CHECK(nb5.read(0, 0, 0, Direction::Horizontal, 20) == "~~~~~~~~~~~~~~~~~~~~");
    CHECK(nb5.read(0, 0, 20, Direction::Horizontal, 10) == "e function");

    CHECK_THROWS(nb5.erase(-1, 0, 0, Direction::Horizontal, 20));
    CHECK_THROWS(nb5.erase(0, -1, 0, Direction::Horizontal, 20));
    CHECK_THROWS(nb5.erase(0, 0, -1, Direction::Horizontal, 20));
    CHECK_THROWS(nb5.erase(0, -1, -1, Direction::Horizontal, 20));
    CHECK_THROWS(nb5.erase(-1, -1, 0, Direction::Horizontal, 20));
    CHECK_THROWS(nb5.erase(-1, 0, -1, Direction::Horizontal, 20));
    CHECK_THROWS(nb5.erase(-1, -1, -1, Direction::Horizontal, 20));
    CHECK_THROWS(nb5.erase(-1, -1, -1, Direction::Horizontal, -1));
    CHECK_THROWS(nb5.erase(0, 0, 0, Direction::Horizontal, -1));
}