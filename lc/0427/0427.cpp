// 0427. Construct Quad Tree
// Problem definition: https://leetcode.com/problems/construct-quad-tree/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

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
