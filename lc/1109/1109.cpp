// 1109. Corporate Flight Bookings
// Problem definition: https://leetcode.com/problems/corporate-flight-bookings/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    std::vector<int> corpFlightBookings(std::vector<std::vector<int>>& bookings, int n) {
        std::vector<int> seats(n, 0);
        for (const auto& flights : bookings) {
            int start {flights[0]-1};
            int end {flights[1]-1};
            int booked {flights[2]};
            for (int i {start}; i <= end; ++i) {
                seats[i] += booked;
            }
        }
        return seats;
    }
};

TEST_CASE("LC test cases", "[Corporate Flight Bookings]") {
    std::vector<std::pair<std::pair<std::vector<std::vector<int>>,int>,std::vector<int>>> input {
        {{{{1,2,10},{2,3,20},{2,5,25}},5},{10,55,45,25,25}},
        {{{{1,1,10},{1,1,20},{1,1,25}},1},{55}},
        {{{{1,1,10},{3,3,20},{5,5,25}},5},{10,0,20,0,25}}
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
