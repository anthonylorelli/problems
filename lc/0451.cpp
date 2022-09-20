// 0451. Sort Characters By Frequency
// Problem definition: https://leetcode.com/problems/sort-characters-by-frequency/
// Accepted 2022-09-14
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <numeric>

class Solution {
public:
    std::string frequencySort(std::string s) {
        std::pair<int,char> count[128]{};
        for (auto c : s) {
            count[c].first++;
            count[c].second = c;
        }
        std::sort(std::begin(count), std::end(count), [](auto a, auto b) {
            return a.first == b.first ? a.second > b.second : a.first > b.first;
        });
        std::string answer;
        for (size_t i {0}; count[i].first != 0; ++i) {
            auto c {count[i].second};
            for (size_t j {0}; j < count[i].first; ++j) {
                answer.push_back(c);
            }
        }
        return answer;
    }

    std::string frequencySort_secondsuccess(std::string s) {
        int count[128]{};
        for (auto c : s) {
            count[c]++;
        }
        std::string answer {s};
        std::sort(answer.begin(), answer.end(), [&count](auto a, auto b) {
            return count[a] == count[b] ? a > b : count[a] > count[b];
        });
        return answer;
    }

    std::string frequencySort_firstsuccess(std::string s) {
        int count[256]{};
        for (auto c : s) {
            count[c]++;
        }
        auto cmp = [](const std::pair<int,char>& a, const std::pair<int,char>& b) {
            return a.first == b.first ? a.second > b.second : a.first < b.first;
        };

        std::priority_queue<std::pair<int,char>,std::vector<std::pair<int,char>>,decltype(cmp)> queue{cmp};
        for (auto c : s) {
            queue.push({count[c],c});
        }
        std::string answer;
        for (; !queue.empty(); queue.pop()) {
            answer.push_back(queue.top().second);
        }
        return answer;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::string,std::string>> input {
        {"tree","eetr"},
        {"cccaaa","cccaaa"},
        {"Aabb","bbaA"},
        {"z","z"},
        {"ddddddddddd","ddddddddddd"},
        {"122333","333221"},
        {"loveleetcode","eeeeoollvtdc"}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.frequencySort(testInput) == expected);
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
