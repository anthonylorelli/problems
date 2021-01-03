// 0088. Merge Sorted Array
// Problem definition: https://leetcode.com/problems/merge-sorted-array/
// Accepted 2021-01-02
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <tuple>
#include <functional>

class Solution {
public:
    // void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    //     auto first = nums1.begin();
    //     auto second = nums2.begin();
    // }

    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        std::merge(nums1.rbegin() + n, nums1.rend(), nums2.rbegin(), nums2.rend(), nums1.rbegin(), std::greater<int>{});
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<
        std::tuple<
            std::pair<std::vector<int>,int>,
            std::pair<std::vector<int>,int>,
            std::vector<int>
            >> input {
        {{{1,2,3,0,0,0},3},{{2,5,6},3},{1,2,2,3,5,6}},
        {{{1},1},{{},0},{1}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [firstInput, secondInput, expected] = p;
                s.merge(firstInput.first, firstInput.second, secondInput.first, secondInput.second);
                REQUIRE(firstInput.first == expected);
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
