// 0743. Network Delay Time
// Problem definition: https://leetcode.com/problems/network-delay-time/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

class Solution {
public:
    int networkDelayTime(std::vector<std::vector<int>>& times, int N, int K) {
        
        return 0;
    }
};

auto speed=[]() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

TEST_CASE("LC test cases", "[Non-decreasing Array]") {
    SECTION("Case 1") {
        std::vector<std::vector<int>> input = {{2,1,1},{2,3,1},{3,4,1}};
        int n {4}, k {2};
        Solution s;
        REQUIRE(s.networkDelayTime(input, n, k) == 2);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
