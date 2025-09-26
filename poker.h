#ifndef POKER_H
#define POKER_H

#include <iostream>
using namespace std;

/*
Below is our wishlist of functions to implement.

Typically I reccomend implementing one at a time. My strategy is to
start by 

a) write the function header and comments as demonstarted below
b) choose a function and write some test cases for it (see tests.cpp)
c) implement the function
d) run the tests to verify it works

Repeat for each function in the wishlist, one at a time, until all functions are done and the tests pass.

Then you are ready to implement main.cpp. It is also valid to start with main.cpp
and and sketch out the structure of the program, then implement the functions one at a time.

*/

// Global game compile time constants
// Always be sure to explain what each constant represents

/// @brief Number of cards in a poker hand
constexpr int HAND_SIZE   = 5;

/// @brief Lowest numeric card value allowed in this game
constexpr int LOWEST_NUM  = 2;

/// @brief Highest numeric card value allowed in this game. (no face cards)
constexpr int HIGHEST_NUM = 9;

/**
 * @brief Builds a frequency table of how many times each card value appears.
 * @param hand The array of cards in the hand.
 * @param counts Output array, where counts[i] = how many times value i appears.
 */
void buildCounts(const int hand[], int counts[]);

/**
 * @brief Returns true if the hand contains exactly one pair.
 * A pair is exactly two of the same card (not 3 or 4).
 */
bool containsPair(const int hand[]);


/**
 * @brief Returns true if the hand contains two different pairs.
 */
bool containsTwoPair(const int hand[]);

/*
Your turn. 

Add next function header and comments here.
then go write a test for it.
then implement it.
then see if it passes the test
*/

#endif