// 1049. Last Stone Weight II
// Problem definition: https://leetcode.com/problems/last-stone-weight-ii/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

class Solution {
public:
    int lastStoneWeightII(std::vector<int>& stones) {
        std::priority_queue q {std::less<int>(), std::move(stones)};

        while (!q.empty()) {
            auto n1 {q.top()};
            q.pop();
            if (q.empty()) { return n1; }
            auto n2 {q.top()};
            q.pop();
            if (n1 < n2) { std::swap(n1, n2); }
            auto n3 {n1 - n2};
            if (n3) { q.push(n3); }
        }
        return 0;
    }
};

TEST_CASE("LC test cases", "[Last Stone Weight II]") {
    Solution s;
    std::vector<std::pair<std::vector<int>,int>> input {
        {{2,7,4,1,8,1}, 1}, {{7,4}, 3}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&s, &input](auto& p) { 
                REQUIRE(s.lastStoneWeightII(p.first) == p.second); 
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
