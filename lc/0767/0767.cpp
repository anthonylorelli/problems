// 0767. Reorganize String
// Problem definition: https://leetcode.com/problems/reorganize-string/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/treenode.h"
#include "../../inc/serialize.h"

#include <algorithm>
#include <string>

class Solution {
public:
    std::string reorganizeString(std::string s) {
        return "";
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::string,std::string>> input {
        {"aab","aba"},
        {"aaab",""}
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
