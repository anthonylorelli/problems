// 0427. Construct Quad Tree
// Problem definition: https://leetcode.com/problems/construct-quad-tree/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* construct(std::vector<std::vector<int>>& grid, size_t startr, size_t startc, size_t extent) {
        auto i {grid[startr][startc]};
        auto rowbegin {grid.cbegin() + startr};
        auto rowend {rowbegin + extent};
        if (std::all_of(rowbegin, rowend, 
            [startc, extent, i](const auto& row) { 
                auto cbegin {row.cbegin() + startc};
                auto cend {cbegin + extent};
                return std::all_of(cbegin, cend, [i](const auto& c) { return c == i; }); 
            })) {
            return new Node(i, true, nullptr, nullptr, nullptr, nullptr);
        } else {
            size_t half {extent / 2};
            return new Node(i, false,
                construct(grid, startr, startc, half),
                construct(grid, startr, startc + half, half),
                construct(grid, startr + half, startc, half),
                construct(grid, startr + half, startc + half, half));
        }
    }
    Node* construct(std::vector<std::vector<int>>& grid) {
        return construct(grid, 0, 0, grid.size());
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    return Catch::Session().run(argc, argv);
    //return execute(std::cin, std::cout);
}

TEST_CASE("", "[Construct Quad Tree]") {
    SECTION("Base case") {
        Solution s;
        std::vector<std::vector<int>> grid {{1, 1}, {1, 1}};
        Node* n {s.construct(grid)};
        REQUIRE(n->isLeaf == true);
        REQUIRE(n->val == true);
    }
}
