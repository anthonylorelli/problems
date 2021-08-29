// 1130. Minimum Cost Tree From Leaf Values
// Problem definition: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
// Accepted 2020-12-04
// Cf. https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/discuss/340033/C%2B%2B-with-comments
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    int mctFromLeafValues(std::vector<int>& arr) {
        for (int i {0}; i < arr.size(); ++i) {
            m_max[i][i] = arr[i];
            for (int j {i + 1}; j < arr.size(); ++j) {
                m_max[i][j] = std::max(m_max[i][j-1], arr[j]);
            }
        }

        return calculate(0, arr.size() - 1);
    }

    Solution() : m_memo(41, std::vector<int>(41,-1)), m_max(41, std::vector<int>(41,0)) { }

private:
    int calculate(const int left, const int right) {
        if (left == right) { return 0; }
        if (m_memo[left][right] != -1) { return m_memo[left][right]; }

        int answer {std::numeric_limits<int>::max()};

        for (int i {left}; i < right; ++i) {
            answer = std::min(answer, m_max[left][i] * m_max[i+1][right] + 
                calculate(left, i) + calculate(i+1, right));
        }

        m_memo[left][right] = answer;
        return answer;
    }

    std::vector<std::vector<int>> m_memo;
    std::vector<std::vector<int>> m_max;
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::vector<int>,int>> input {
        {{6,2,4},32}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.mctFromLeafValues(testInput) == expected);
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
