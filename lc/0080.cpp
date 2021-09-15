// 0080. Remove Duplicates from Sorted Array II
// Problem definition: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Accepted 2020-11-28
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return nums.size();
        }
        int left {0};
        for (int right {1}; right < nums.size(); ++right) {
            if (nums[left] != nums[right]) {
                ++left;
                nums[left] = nums[right];
            } else {
                ++left;
                auto current = nums[left] = nums[right];
                while ((right + 1) < nums.size() && nums[right + 1] == current) { ++right; }
            }
        }
        return left + 1;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::vector<int>,std::pair<std::vector<int>,int>>> input {
        {{1,2,3},{{1,2,3},3}},
        {{1,1,1,2,2,3},{{1,1,2,2,3},5}},
        {{},{{},0}},
        {{1},{{1},1}},
        {{1,1,2,3},{{1,1,2,3},4}},
        {{1,2,3,3,3},{{1,2,3,3},4}},
        {{1,1,1,1},{{1,1},2}},
        {{1,2,2,2},{{1,2,2},3}},
        {{1,2,2,2,3},{{1,2,2,3},4}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                auto& [output, count] = expected;
                REQUIRE(s.removeDuplicates(testInput) == count);
                for (int i {0}; i < count; ++i) {
                    REQUIRE(testInput[i] == output[i]);
                }
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
