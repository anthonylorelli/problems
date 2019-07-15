// 0390. Elimination Game
// Problem definition: https://leetcode.com/problems/elimination-game/description/
// Accepted ?
// Compare: https://en.wikipedia.org/wiki/Josephus_problem

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int lastRemaining(int n) {
        std::vector<int> v(n);
        std::iota(v.begin(), v.end(), 1);
        bool from_start {true};
        while (v.size() > 1) {
            bool do_remove = from_start ? true : v.size() % 2 == 1 ? true : false;
            v.erase(std::remove_if(v.begin(), v.end(),
                [&v, &do_remove](const int n) { bool state {do_remove}; do_remove = !do_remove; return state; }),
                v.end());
            from_start = !from_start;
        }
        return v[0];
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
        //REQUIRE(s.lastRemaining(9) == 6);
        for (int i {1}; i < 200; ++i) {
            std::cout << "[" << i << "] " << s.lastRemaining(i) << "\n";
        }        
    }
}
