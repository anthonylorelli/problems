// 0778. Swim in Rising Water
// Problem definition: https://leetcode.com/problems/swim-in-rising-water/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>
#include <algorithm>
#include <vector>

struct Node
{
    Node(const int distance, const bool visited) : x{0}, y{0}, distance{distance}, visited{visited} {}
    int x;
    int y;
    int distance;
    bool visited;
};

class Solution {
public:
    static constexpr int c_max_time {51};

    template <typename T>
    void addAdjacent(const Node& n) {

    }

    int swimInWater(std::vector<std::vector<int>>& grid) {
        auto size {grid.size()};
        auto l {[](const Node& l, const Node& r) { return l.distance > r.distance; }};
        std::vector q(size*size, Node(c_max_time, false));

        int x {0}, y {0};
        for (auto& i : q) {
            i.x = x++; i.y = y;
            if (x == size) { y++; x = 0; }
        }

        q[0].distance = 0;

        std::make_heap(q.begin(), q.end(), l);

        while (!q.empty()) {
            std::pop_heap(q.begin(), q.end(), l);
            auto n {q.back()};
            q.pop_back();
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
