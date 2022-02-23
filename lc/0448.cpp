// 0448. Find All Numbers Disappeared in an Array
// Problem definition: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
// Accepted 2020-12-19
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        std::vector<int> result;
        for (int i {0}; i < nums.size(); ++i) {
            while (nums[i] != (i + 1) && nums[i] != nums[nums[i] - 1]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i {0}; i < nums.size(); ++i) {
            if (nums[i] != (i + 1)) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::vector<int>,std::vector<int>>> input {
        {{4,3,2,7,8,2,3,1},{5,6}},
        {{1,1,2,2,3,3},{4,5,6}},
        {{6,6,5,5,4,4},{1,2,3}},
        {{6,1,4,2,1,6},{3,5}},
        {{5,4,3,2,1},{}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.findDisappearedNumbers(testInput) == expected);
            });
    }
}

auto speed=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
