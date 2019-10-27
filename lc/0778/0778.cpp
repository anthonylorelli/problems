// 0778. Swim in Rising Water
// Problem definition: https://leetcode.com/problems/swim-in-rising-water/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>
#include <algorithm>
#include <vector>
#include <limits>

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
    static constexpr int c_max_time {std::numeric_limits<int>::max()};

    void updateLocation(const int x, const int y, const int distance, std::vector<std::vector<Node>>& nodes) {

    }

    void addAdjacent(const Node& n, std::vector<std::vector<Node>>& nodes, std::vector<std::vector<int>>& distances) {
        int x {n.x}, y {n.y};
        if (x > 0 && !nodes[x-1][y].visited) {
            int distance = distances[x-1][y];
            if (distance < n.distance) { distance = n.distance; }
            if (nodes[x-1][y].distance > distance) {
                nodes[x-1][y].distance = distance;
            }
        }
        if (y > 0 && !nodes[x][y-1].visited) {
            int distance = distances[x][y-1];
            if (distance < n.distance) { distance = n.distance; }
            if (nodes[x][y-1].distance > distance) {
                nodes[x][y-1].distance = distance;
            }
        }
        auto size {nodes.size()};
        if (x < size - 1 && !nodes[x+1][y].visited) {
            int distance = distances[x+1][y];
            if (distance < n.distance) { distance = n.distance; }
            if (nodes[x+1][y].distance > distance) {
                nodes[x+1][y].distance = distance;
            }
        }
        if (y < size - 1 && !nodes[x][y+1].visited) {
            int distance = distances[x][y+1];
            if (distance < n.distance) { distance = n.distance; }
            if (nodes[x][y+1].distance > distance) {
                nodes[x][y+1].distance = distance;
            }
        }
    }

    int swimInWater(std::vector<std::vector<int>>& grid) {
        auto size {grid.size()};
        auto l {[](const Node* l, const Node* r) { return l->distance > r->distance; }};
        std::vector<std::vector<Node>> nodes(size, std::vector(size, Node(c_max_time, false)));
        std::vector<Node*> q(size*size);

        for (int x {0}; x < size; ++x) {
            for (int y {0}; y < size; ++y) {
                Node& n {nodes[x][y]};
                n.x = x; n.y = y;
                q[(x * size) + y] = &n;
            }
        }

        nodes[0][0].distance = 0;

        std::make_heap(q.begin(), q.end(), l);

        while (!q.empty()) {
            std::pop_heap(q.begin(), q.end(), l);
            auto n {q.back()};
            if (n->x == size - 1 && n->y == size - 1) { return n->distance; }
            q.pop_back();
            addAdjacent(*n, nodes, grid);
            n->visited = true;
            std::make_heap(q.begin(), q.end(), l);
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
