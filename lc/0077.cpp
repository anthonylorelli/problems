// 0077. Combinations
// Problem definition: https://leetcode.com/problems/combinations/
// Accepted 2021-08-17
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<int> combo(k);
        iterate(1, n, 0, k, combo);
        return m_result;
    }

    void iterate(const int32_t start, const int32_t n, const int32_t index, const int32_t limit, std::vector<int>& combo) {
        if (index == limit) { 
            m_result.push_back(combo);
            return; 
        }
        for (int32_t i {start}; i <= n; ++i) {
            combo[index] = i;
            iterate(i + 1, n, index + 1, limit, combo); 
        }
    }

private:
    std::vector<std::vector<int>> m_result;
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,int,std::vector<std::vector<int>>>> input {
        {4,2,{{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}}},
        {1,1,{{1}}},
        {5,3,{{1,2,3},{1,2,4},{1,2,5},{1,3,4},{1,3,5},{1,4,5},{2,3,4},{2,3,5},{2,4,5},{3,4,5}}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, k, expected] = p;
                REQUIRE(s.combine(testInput, k) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
