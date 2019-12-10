// 1109. Corporate Flight Bookings
// Problem definition: https://leetcode.com/problems/corporate-flight-bookings/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    std::vector<int> corpFlightBookings(std::vector<std::vector<int>>& bookings, int n) {
        return {};
    }
};

TEST_CASE("LC test cases", "[Corporate Flight Bookings]") {
    std::vector<std::pair<std::pair<std::vector<std::vector<int>>,int>,std::vector<int>>> input {
        {{{{1,2,10},{2,3,20},{2,5,25}},5},{10,55,45,25,55}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.corpFlightBookings(testInput.first, testInput.second) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
