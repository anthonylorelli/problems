// 0300. Longest Increasing Subsequence
// Problem definition: https://leetcode.com/problems/longest-increasing-subsequence/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <tuple>
#include <iostream>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<std::tuple<int,int,bool>> seq;
        for (size_t i {0}; i < nums.size(); ++i) {
            seq.push_back({nums[i], i, false});
        }
        std::sort(seq.begin(), seq.end(), [](const auto& a, const auto& b) {
            return std::get<0>(a) == std::get<0>(b) ? std::get<1>(a) < std::get<1>(b) :
                std::get<0>(a) < std::get<0>(b);
        });
        for (const auto& [n, i, used] : seq) {
            std::cout << n << " " << i << " " << used << "\n";
        }
        int max {0};
        for (auto b = seq.begin(); b != seq.end(); ++b) {
            if (!std::get<2>(*b)) {
                std::get<2>(*b) = true;
                max = std::max(max, count(b, seq.end(), 0));
            }
        }
        return 0;
    }

    template<typename It, typename End>
    int count(It begin, End end, int current) {
        auto [bn, bi, bused] = *begin;
        std::cout << "Lower bound " << bn << " " << bi << " " << bused << "\n";
        auto result = std::upper_bound(begin + 1, end, *begin, [](const auto& a, const auto& b) {
            return std::get<0>(a) < std::get<0>(b) && std::get<1>(a) < std::get<1>(b);
        });
        if (result == end) {
            return current;
        }
        auto [n, i, used] = *result;
        std::cout << "Found " << n << " " << i << " " << used << "\n";
        std::get<2>(*result) = true;
        return count(result, end, current + 1);
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int>> input {
        {{10,9,2,5,3,7,101,18},4},{{0,1,0,3,2,3},4},{{7,7,7,7,7,7,7},1}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.lengthOfLIS(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
