// 0767. Reorganize String
// Problem definition: https://leetcode.com/problems/reorganize-string/
// Accepted 2020-12-15
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/treenode.h"
#include "../../inc/serialize.h"

#include <algorithm>
#include <string>
#include <queue>
#include <array>

class Solution {
public:
    std::string reorganizeString(std::string s) {
        std::array<int,26> counts{};
        for (const auto c : s) {
            counts[c - 'a']++;
        }
        auto predicate = [](const auto lhs, const auto rhs) {
            return lhs.second < rhs.second;
        };
        std::priority_queue<std::pair<char,int>, std::vector<std::pair<char,int>>, 
            decltype(predicate)> queue(predicate);
        const auto limit {(s.size() + 1) / 2};
        for (int i {0}; i < 26; ++i) {
            if (counts[i] == 0) {
                continue;
            }
            if (counts[i] > limit) {
                return "";
            }
            queue.push({i + 'a', counts[i]});
        }
        std::string result;
        while (queue.size() > 1) {
            auto [achar, acount] = queue.top();
            queue.pop();
            auto [bchar, bcount] = queue.top();
            queue.pop();
            result.push_back(achar);
            result.push_back(bchar);
            if (--acount > 0) { queue.push({achar, acount}); }
            if (--bcount > 0) { queue.push({bchar, bcount}); }
        }
        if (queue.size() > 0) {
            result.push_back(queue.top().first);
        }
        return result;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::string,std::string>> input {
        {"aab","aba"},
        {"aaab",""},
        {"a", "a"}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.reorganizeString(testInput) == expected);
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
