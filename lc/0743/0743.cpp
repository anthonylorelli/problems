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
#include <forward_list>
#include <limits>

uint32_t c_n {100};

class Solution {
public:
    int networkDelayTime(std::vector<std::vector<int>>& times, int N, int K) {
        size_t size = N + 1;
        std::vector<std::list<std::pair<uint32_t,uint32_t>>> adjacent(size);

        for (const auto& t : times) {
            adjacent[t[0]].push_front({t[1],t[2]});
        }

        auto cmp = [](const auto& x, const auto& y) { return x.second > y.second; };
        std::priority_queue<std::pair<uint32_t,uint32_t>, std::vector<std::pair<uint32_t,uint32_t>>, 
            decltype(cmp)> queue(cmp);

        std::vector<bool> visited(size, false);
        std::vector<uint32_t> distance(size, std::numeric_limits<uint32_t>::max());

        distance[0] = distance[K] = 0;
        queue.push({K,0});

        while (!queue.empty()) {
            auto [current, weight] = queue.top();
            queue.pop();
            if (visited[current]) { continue; }
            visited[current] = true;
            for (const auto [next,cost] : adjacent[current]) {
                if (distance[next] > (distance[current] + cost)) {
                    distance[next] = distance[current] + cost;
                }
                queue.push({next,distance[next]});
            }
        }

        auto max_delay = std::max_element(distance.begin(), distance.end());
        return *max_delay == std::numeric_limits<uint32_t>::max() ? -1 : *max_delay;
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
