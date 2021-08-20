// 0039. Combination Sum
// Problem definition: https://leetcode.com/problems/combination-sum/
// Accepted 2021-08-20
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <functional>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<int> combo;
        for (int32_t i {0}; i < candidates.size(); ++i) {
            combinations(candidates, i, target, combo);
        }
        return m_result;
    }

    void combinations(std::vector<int>& candidates, const int32_t index, const int32_t delta, std::vector<int>& combo) {
        if (delta == 0) { 
            m_result.push_back(combo); 
            return;
        }
        if (index == candidates.size()) {
            return;
        }
        int32_t factor {delta / candidates[index]};
        for (int32_t i {1}; i <= factor; ++i) {
            combo.push_back(candidates[index]);
            combinations(candidates, index + 1, delta - (candidates[index] * i), combo);
        }
        for (int32_t i {0}; i < factor; ++i) {
            combo.pop_back();
        }
        if (combo.size() > 0) {
            combinations(candidates, index + 1, delta, combo);
        }
    }

private:
    std::vector<std::vector<int>> m_result;
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int,std::vector<std::vector<int>>>> input {
        {{2,3,6,7},7,{{2,2,3},{7}}},
        {{2,3,5},8,{{2,3,3},{2,2,2,2},{3,5}}},
        {{2},1,{}},{{1},1,{{1}}},
        {{1},2,{{1,1}}},{{3,5,8},11,{{3,8},{3,3,5}}},
        {{2,7,6,3,5,1},9,{{2,7},{2,6,1},{2,3,1,1,1,1},{2,3,3,1},{2,5,1,1},
            {2,1,1,1,1,1,1,1},{2,2,3,1,1},{2,2,5},{2,2,1,1,1,1,1},{2,2,2,3},
            {2,2,2,1,1,1},{2,2,2,2,1},{7,1,1},{6,3},{6,1,1,1},{3,5,1},{3,1,1,1,1,1,1},
            {3,3,1,1,1},{3,3,3},{5,1,1,1,1},{1,1,1,1,1,1,1,1,1}}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, target, expected] = p;
                REQUIRE(s.combinationSum(testInput, target) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
