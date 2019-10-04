// 0778. Swim in Rising Water
// Problem definition: https://leetcode.com/problems/swim-in-rising-water/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>
#include <algorithm>
#include <vector>

class Solution {
public:
    int c_max_time {51};

    int swimInWater(std::vector<std::vector<int>>& grid) {
        auto size {grid.size()};
        std::vector<std::vector<bool>> visited(size, std::vector(size, false));
        std::vector<std::vector<int>> distance(size, std::vector(size, c_max_time));
        
        int time {0};
        distance[0][0] = 0;
        std::pair<int,int> v{0,0};

        while (!visited[v.first][v.second]) {
            visited[v.first][v.second] = true;
        }

        return 0;        
    }
};

TEST_CASE("LC test cases", "[Swim in Rising Water]") {
    Solution s;
    std::vector<std::pair<std::vector<std::vector<int>>,int>> input {
        {{{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}},16},
        {{{0,2},{1,3}},3}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&s, &input](auto& p) { 
                REQUIRE(s.swimInWater(p.first) == p.second); 
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
