// 0347. Top K Frequent Elements
// Problem definition: https://leetcode.com/problems/top-k-frequent-elements/
// Accepted 2021-08-27
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        if (nums.size() == k) {
            return nums;
        }

        std::unordered_map<int,int> map;
        for (const auto n : nums) {
            map[n]++;
        }

        auto pred = [&map](const auto a, const auto b) {
            return map[a] < map[b];
        };
        std::priority_queue<int, std::vector<int>, decltype(pred)> queue(pred);
        for (const auto [key, value] : map) {
            queue.push(key);
        }

        std::vector<int> result;
        for (int i {0}; i < k; ++i) {
            result.push_back(queue.top());
            queue.pop();
        }

        return result;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int,std::vector<int>>> input {
        {{1,1,1,2,2,3},2,{1,2}},{{1},1,{1}},
        {{1,2,3,4,1,2,3,4,1,2,3,1,2,3,1,2,1,2,1},2,{1,2}},
        {{4,3,2,1,4,3,2,1,4,3,2,4,3,2,4,3,2,4,3,4,3,4},2,{4,3}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, k, expected] = p;
                REQUIRE(s.topKFrequent(testInput, k) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
