// 0040. Combination Sum II
// Problem definition: https://leetcode.com/problems/combination-sum-ii/
// Accepted 2021-01-06
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<int> seq;
        std::vector<std::vector<int>> result;
        walk(candidates, 0, target, seq, result);
        return result;
    }

private:
    void walk(const std::vector<int>& candidates, const int current, const int remaining, 
        std::vector<int>& seq, std::vector<std::vector<int>>& result) {
        if (remaining == 0) {
            result.push_back(seq);
            return;
        }

        for (int i {current}; i < candidates.size(); ++i) {
            if (i > current && candidates[i] == candidates[i - 1]) {
                continue;
            }

            const int next {candidates[i]};
            if (remaining - next < 0) {
                return;
            }

            seq.push_back(next);
            walk(candidates, i + 1, remaining - next, seq, result);
            seq.pop_back();
        }
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int,std::vector<std::vector<int>>>> input {
        {{10,1,2,7,6,1,5},8,{{1,1,6},{1,2,5},{1,7},{2,6}}},
        {{2,5,2,1,2},5,{{1,2,2},{5}}},
        {{1,1,1},2,{{1,1}}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, target, expected] = p;
                REQUIRE(s.combinationSum2(testInput, target) == expected);
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
