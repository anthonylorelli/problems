// 0027. Remove Element
// Problem definition: https://leetcode.com/problems/remove-element/
// 2020-02-18

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};

TEST_CASE("LC test cases", "[Remove Element]") {
    std::vector<std::pair<std::pair<std::vector<int>,int>,std::pair<std::vector<int>,int>>> input {
        {{{3,2,2,3},3},{{2,2},2}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.removeElement(testInput.first, testInput.second) == expected.second);
                REQUIRE(testInput.first == expected.first);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
