// 1629. Slowest Key
// Problem definition: https://leetcode.com/problems/slowest-key/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/treenode.h"

#include <algorithm>
#include <vector>
#include <string>

class Solution {
public:
    char slowestKey(std::vector<int>& releaseTimes, std::string keysPressed) {
        return '';
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,std::string,char> input {
        {{9,29,49,50},"cbcd",'c'},{{12,23,36,46,62},"spuda",'a'}
    };

    SECTION("Test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&](auto& p) {
                auto& [testInput, keysPress, expected] = p;
                REQUIRE(Solution{}.slowestKey(testInput, keysPressed) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
