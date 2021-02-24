// 0621. Task Scheduler
// Problem definition: https://leetcode.com/problems/task-scheduler/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        return 0;        
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<char>,int,int>> input {
        {{"A","A","A","B","B","B"},2,8},
        {{"A","A","A","B","B","B"},0,6},
        {{"A","A","A","A","A","A","B","C","D","E","F","G"},2,16}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, n, expected] = p;
                REQUIRE(s.leastInterval(testInput, n) == expected);
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
