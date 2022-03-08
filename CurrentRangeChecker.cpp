#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "CurrentRangeUpdate.h"

TEST_CASE("Checks if count is updated with single continuous range of current values") {
    int CurrentValues[] = {4,5};
	REQUIRE(CurrentRangeUpdate(CurrentValues, 2) == 1);
}

TEST_CASE("Checks if range and count is updated with multiple range of sorted current values") {
    int CurrentValues[] = {2,2,2,3,3,4,6,6,7,8,8,9,9,10};
	REQUIRE(CurrentRangeUpdate(CurrentValues, 14) == 2);
}