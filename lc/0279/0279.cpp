// 0279. Perfect Squares
// Problem definition: https://leetcode.com/problems/perfect-squares/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <tuple>

class Solution {
public:
    int numSquares(int n) {
        return 0;        
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,int>> input {
        {12,3},
        {13,2}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.numSquares(testInput) == expected);
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
