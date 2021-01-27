// 0062. Unique Paths
// Problem definition: https://leetcode.com/problems/unique-paths/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <vector>
#include <algorithm>

class Solution {
public:
    int uniquePaths(int m, int n) {
        return 0;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,int,int>> input {
        {3,7,28},
        {3,2,3},
        {7,3,28},
        {3,3,6}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [m, n, expected] = p;
                REQUIRE(s.uniquePaths(m, n) == expected);
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
