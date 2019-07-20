// 0935. Knight Dialer
// Problem definition: https://leetcode.com/problems/knight-dialer/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

class Solution {
public:
    int knightDialer(int N) {
        return 0;        
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    return Catch::Session().run(argc, argv);
    //return execute(std::cin, std::cout);
}

TEST_CASE("", "[Knight Dialer]") {
    SECTION("LC test case 1-3") {
        Solution s;
        REQUIRE(s.knightDialer(1) == 10);
        REQUIRE(s.knightDialer(2) == 20);
        REQUIRE(s.knightDialer(3) == 46);
    }
}
