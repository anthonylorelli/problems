// 0390. Elimination Game
// Problem definition: https://leetcode.com/problems/elimination-game/description/
// Accepted 2019-07-15
// Compare: https://en.wikipedia.org/wiki/Josephus_problem
// Enlightening discussion here: https://leetcode.com/problems/elimination-game/discuss/87159/O(1)java-solution-with-detailed-explanation(actually-lots-of-math-derivation)

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int lastRemaining(int n) {
        return n == 1 ? 1 : 2 * (n/2 + 1 - lastRemaining(n/2));
    }

    int lastRemaining2(int n) {
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
        for (int i {1}; i < 200; ++i) {
            std::cout << "[" << i << "] " << s.lastRemaining(i) << "\n";
            REQUIRE(s.lastRemaining(i) == s.lastRemaining2(i));
        }
    }
}
