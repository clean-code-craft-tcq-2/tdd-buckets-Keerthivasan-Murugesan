#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "CurrentRangeUpdate.h"
/*
TEST_CASE("Checks if count is updated with single continuous range of current values") {
    int CurrentValues[] = {4,5};
	REQUIRE(CurrentRangeUpdate(CurrentValues, 2) == 1);
}*/

TEST_CASE("Checks if range and count is updated with multiple range of sorted current values") {
    int CurrentValues[] = {3,3,4,5,7,8,10,11,11,12};
	REQUIRE(CurrentRangeUpdate(CurrentValues, 10) == 3);
}