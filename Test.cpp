#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good snowman code NO SPACES") {
    //the test does not check spaces
    CHECK(snowman(11114411) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(snowman(33232124) == nospaces("_\n/_\\\n\\(o_O)\n(] [)>\n(   )"));
    CHECK(snowman(11111111) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
    CHECK(snowman(22222222) == nospaces("___\n.....\n\\(o.o)/\n(] [)\n(\" \")"));
    CHECK(snowman(33333333) == nospaces("_\n/_\\\n(0_0)\n/(> <)\\\n(___)"));
    CHECK(snowman(44444444) == nospaces("___\n(_*_)\n(- -)\n(   )\n(   )"));
    CHECK(snowman(12341234) == nospaces("_===_\n(0.-)/\n<(> <)\n(   )"));
    CHECK(snowman(43214321) == nospaces("___\n(_*_)\n(o_.)\\n(] [)\n( : )"));
    CHECK(snowman(44441111) == nospaces("___\n(_*_)\n(- -)\n<( : )>\n( : )"));
    CHECK(snowman(11114444) == nospaces("_===_\n(.,.)\n(   )\n(   )"));
}

TEST_CASE("short snowman code") {
    CHECK_THROWS(snowman(555));
    CHECK_THROWS(snowman(123));
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(22));
    CHECK_THROWS(snowman(21342));
    CHECK_THROWS(snowman(1234));
    CHECK_THROWS(snowman(124123));
    CHECK_THROWS(snowman(1243214));
}

TEST_CASE("long snowman code")
{
    CHECK_THROWS(snowman(141232412));
    CHECK_THROWS(snowman(111111111));
}

TEST_CASE("has minus")
{
    CHECK_THROWS(snowman(-11111111));
    CHECK_THROWS(snowman(2-4123412));
    CHECK_THROWS(snowman(2341234-1));
    CHECK_THROWS(snowman(2341-2341));
}

TEST_CASE("bigger then 4")
{
    CHECK_THROWS(snowman(51234231));
    CHECK_THROWS(snowman(15342142));
    CHECK_THROWS(snowman(32541212));
}

