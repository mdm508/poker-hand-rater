#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "poker.h"


TEST_CASE("buildCounts counts each card value correctly") {
    int hand[5] = {2, 3, 3, 5, 9};
    int counts[HIGHEST_NUM + 1];

    buildCounts(hand, counts);

    REQUIRE(counts[2] == 1);  // one 2
    REQUIRE(counts[3] == 2);  // two 3s
    REQUIRE(counts[5] == 1);  // one 5
    REQUIRE(counts[9] == 1);  // one 9

    for (int i = LOWEST_NUM; i <= HIGHEST_NUM; i++) {
        if (i != 2 && i != 3 && i != 5 && i != 9) {
            REQUIRE(counts[i] == 0);
        }
    }
}

TEST_CASE("containsPair returns true only for exactly one pair") {
    SECTION("Simple pair") {
        int hand[5] = {2, 2, 3, 4, 5};
        REQUIRE( containsPair(hand) );
    }
    SECTION("No pair") {
        int hand[5] = {2, 3, 4, 5, 6};
        REQUIRE_FALSE( containsPair(hand) );
    }
    SECTION("Three of a kind is not a pair") {
        int hand[5] = {2, 2, 2, 4, 5};
        REQUIRE_FALSE( containsPair(hand) );
    }
    SECTION("Two pair is not a single pair") {
        int hand[5] = {2, 2, 3, 3, 4};
        REQUIRE_FALSE( containsPair(hand) );
    }
}

TEST_CASE("containsTwoPair detects two distinct pairs and nothing else") {
    SECTION("Two different pairs") {
        int hand[5] = {2, 2, 3, 3, 4};
        REQUIRE( containsTwoPair(hand) );
    }
    SECTION("Full house is not two pair") {
        int hand[5] = {2, 2, 3, 3, 3};
        REQUIRE_FALSE( containsTwoPair(hand) );
    }
    SECTION("One pair only") {
        int hand[5] = {2, 2, 4, 5, 6};
        REQUIRE_FALSE( containsTwoPair(hand) );
    }
    SECTION("No pair at all") {
        int hand[5] = {2, 3, 4, 5, 6};
        REQUIRE_FALSE( containsTwoPair(hand) );
    }
}