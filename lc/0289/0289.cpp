// 0289. Game of Life
// Problem definition: https://leetcode.com/problems/game-of-life/
// Accepted ?


#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    void gameOfLife(std::vector<std::vector<int>>& board) {
        
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    return Catch::Session().run(argc, argv);
    //return execute(std::cin, std::cout);
}

TEST_CASE("", "[Game of Life]") {
    SECTION("") {
        REQUIRE(true);
    }
}
