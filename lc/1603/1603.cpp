// 1603. Design Parking System
// Problem definition: https://leetcode.com/problems/design-parking-system/
// Accepted 2021-04-24
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <numeric>
#include <vector>

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        m_current[1] = big;
        m_current[2] = medium;
        m_current[3] = small;
    }
    
    bool addCar(int carType) {
        if (m_current[carType] > 0) {
            m_current[carType]--;
            return true;
        }
        return false;
    }

private:
    int32_t m_current[4]{};
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

// TEST_CASE("LC test cases", "[Core]") {
//     std::vector<std::tuple<std::vector<std::vector<int>>,int>> input {
//         {{{1,2,3},{3,2,1}},6},{{{1,5},{7,3},{3,5}},10},{{{2,8,7},{7,1,3},{1,9,5}},17}
//     };

//     SECTION("Test cases") {
//         std::for_each(std::begin(input), std::end(input),
//             [&](auto& p) {
//                 auto& [testInput, expected] = p;
//                 REQUIRE(Solution{}.maximumWealth(testInput) == expected);
//             });
//     }
// }

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
