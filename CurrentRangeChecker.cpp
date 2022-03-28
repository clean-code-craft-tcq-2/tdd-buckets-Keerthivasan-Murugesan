#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "CurrentRangeUpdate.h"

TEST_CASE("Checks if number of ranges is updated with single continuous range of current values") {
    int CurrentValues[] = {4,5};
	REQUIRE(CurrentRangeUpdate(CurrentValues, 2) == 1);
}

TEST_CASE("Checks if number of ranges is updated with multiple range of sorted current values") {
    int CurrentValues[] = {2,2,2,3,3,4,6,6,7,8,8,9,9,10,14,17,18,21};
	REQUIRE(CurrentRangeUpdate(CurrentValues, 18) == 5);
}

TEST_CASE("Checks if number of ranges is updated with multiple range of unsorted current values") {
    int CurrentValues[] = {3,5,4,2,3,10,7,11,6,12};
	REQUIRE(CurrentRangeUpdate(CurrentValues, 10) == 2);
}

TEST_CASE("Checks if range and count is updated with multiple range of unsorted current values") {
    int CurrentValues[] = {3,5,4,2,3,10,7,11,6,12};
    int expectedOutput[2][3] = {{2,7,7}, {10,12,3}};
    REQUIRE(CurrentRangeUpdate(CurrentValues, 10) == 2);

    for(int i = 0; i<2; i++){
        for(int j = 0; j<3; j++){
            REQUIRE(expectedOutput[i][j] == CurrentRangesWithCount[i][j]);
        }
    }
}

TEST_CASE("Checks if number of ranges is updated with current values from 12-bit A2D converter") {
    long int CurrentValues[] = {011010, 01101101, 10110110, 111011101110, 00100100101, 1101, 101010101010, 011111111111};
	REQUIRE(CurrentRangeUpdate_Binary(CurrentValues, 8) == 2);
}