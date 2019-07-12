// 0390. Elimination Game
// Problem definition: https://leetcode.com/problems/elimination-game/description/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

class Solution {
public:
    int lastRemaining(int n) {
        return 0;
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    return Catch::Session().run(argc, argv);
    //return execute(std::cin, std::cout);
}

TEST_CASE("", "[Elimination Game]") {
    SECTION("LC test case 1") {
        Solution s;
        REQUIRE(s.lastRemaining(9) == 6);
    }
}
