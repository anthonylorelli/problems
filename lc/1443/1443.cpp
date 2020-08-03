// 1443. Minimum Time to Collect All Apples in a Tree
// Problem definition: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <forward_list>
#include <limits>

class Solution {
public:
    int minTime(int n, std::vector<std::vector<int>>& edges, std::vector<bool>& hasApple) {
        const size_t size = n + 1;
        std::vector<std::vector<int>> adjacent(size);
        for (const auto& edge : edges) {
            adjacent[edge[0]].push_back(edge[1]);
        }
        return 0;
    }
};

auto speed=[]() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

TEST_CASE("LC test cases", "[Core]") {
    SECTION("Case 1") {
        std::vector<std::vector<int>> edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
        std::vector<bool> has_apple = {false,false,true,false,true,true,false};
        int n {4};
        Solution s;
        REQUIRE(s.minTime(n, edges, has_apple) == 8);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
