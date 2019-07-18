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
    Node* construct(std::vector<std::vector<int>>& grid, size_t startc, size_t startr, size_t extent) {
        auto i {grid[startc][startr]};
        auto colbegin {grid.cbegin() + startc};
        auto colend {colbegin + extent};
        if (std::all_of(colbegin, colend, 
            [startr, extent, i](const auto& row) { 
                auto rbegin {row.cbegin() + startr};
                auto rend {rbegin + extent};
                return std::search_n(rbegin, rend, extent, i) == rend; 
            })) {
            return new Node(i, true, nullptr, nullptr, nullptr, nullptr);
        } else {
            return nullptr;
        }
    }
    Node* construct(std::vector<std::vector<int>>& grid) {
        return nullptr;        
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    return Catch::Session().run(argc, argv);
    //return execute(std::cin, std::cout);
}

TEST_CASE("", "[Construct Quad Tree]") {
    SECTION("LC test case 1") {
        
    }
}
