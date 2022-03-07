/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: renana rimon
 *
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input)
{
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}

TEST_CASE("Good input")
{
    CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
                                                    "@-------@\n"
                                                    "@-@@@@@-@\n"
                                                    "@-@---@-@\n"
                                                    "@-@@@@@-@\n"
                                                    "@-------@\n"
                                                    "@@@@@@@@@"));

    CHECK(nospaces(mat(1, 1, '@', '-')) == "@");
    CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
                                                     "@-----------@\n"
                                                     "@-@@@@@@@@@-@\n"
                                                     "@-----------@\n"
                                                     "@@@@@@@@@@@@@"));

    CHECK(nospaces(mat(3, 5, '*', '+')) == "****+**+**+****");
    CHECK(nospaces(mat(5, 3, '*', '+')) == "******+++******");
    CHECK(nospaces(mat(1, 5, '*', '+')) == "*****");
    CHECK(nospaces(mat(5, 1, '*', '+')) == "*****");
    CHECK((mat(5, 1, '*', '+')) == "*****\n");
    CHECK((mat(1, 5, '*', '+')) == "*\n*\n*\n*\n*\n");

}

TEST_CASE("Bad input")
{
    CHECK_THROWS(mat(10, 5, '$', '%'));

    /** if row or col is even - Invalid*/
    for (size_t i = 0; i < 15; i++)
    {
        if (i % 2 == 0)
        {
            CHECK_THROWS(mat(i, 1, '$', '%'));
            CHECK_THROWS(mat(1, i, '$', '%'));
            CHECK_THROWS(mat(i, i, '$', '%'));
        }
    }

}

/* Add more test cases here */
TEST_CASE("Palindrom")
{
    string st = "";
    for (size_t k = 1, m = 11; k < 100 && m < 110; k += 2, m += 2)
    {
        st = nospaces(mat(k, m, '@', '-'));
        int len = st.length();
        for (size_t i = 0, j = len-1; i < j; i++, j--)
        {
            if (st[i] != st[j])
            {
                FAIL_CHECK("failed");
                cout << "i: " << st[i] << "j: " << st[j] << endl;
                break;
            }
        }
        cout << "TEST SUCCEED\n";
    }
}

TEST_CASE("more tests"){
    CHECK(nospaces(mat(3,3, '@', '-')) == "@@@@-@@@@");
    CHECK(nospaces(mat(5,5, '@', '-')) == "@@@@@@---@@-@-@@---@@@@@@");
    CHECK(nospaces(mat(1, 1, '@', '-')) == "@");
    CHECK(nospaces(mat(51, 3, '@', '-')) == nospaces("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                                                        "@-------------------------------------------------@\n"
                                                        "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"));
    CHECK(nospaces(mat(9,11, '@', '-')) == nospaces("@@@@@@@@@\n"
                                                    "@-------@\n"
                                                    "@-@@@@@-@\n"
                                                    "@-@---@-@\n"
                                                    "@-@-@-@-@\n"
                                                    "@-@-@-@-@\n"
                                                    "@-@-@-@-@\n"
                                                    "@-@---@-@\n"
                                                    "@-@@@@@-@\n"
                                                    "@-------@\n"
                                                    "@@@@@@@@@\n"));

    CHECK(nospaces(mat(13,15, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
                                                    "@-----------@\n"
                                                    "@-@@@@@@@@@-@\n"
                                                    "@-@-------@-@\n"
                                                    "@-@-@@@@@-@-@\n"
                                                    "@-@-@---@-@-@\n"
                                                    "@-@-@-@-@-@-@\n"
                                                    "@-@-@-@-@-@-@\n"
                                                    "@-@-@-@-@-@-@\n"
                                                    "@-@-@---@-@-@\n"
                                                    "@-@-@@@@@-@-@\n"
                                                    "@-@-------@-@\n"
                                                    "@-@@@@@@@@@-@\n"
                                                    "@-----------@\n"
                                                    "@@@@@@@@@@@@@\n"));

    

}
