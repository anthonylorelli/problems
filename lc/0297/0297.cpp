// 0297. Serialize and Deserialize Binary Tree
// Problem definition: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>

/**
 * Definition for a binary tree node.
 */ 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
public:
    std::string serialize(TreeNode* root) {
        if (!root) { return "[]"; }
        std::string result {"["};
        
        std::queue<TreeNode*> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            int count = queue.size();
            for (int n {0}; n < count; ++n) {
                if (n) { 
                    result += ",";
                }
                TreeNode* next {queue.front()};
                queue.pop();
                if (next) {
                    result += std::to_string(next->val);
                    if (next->left || next->right) {
                        queue.push(next->left);
                        queue.push(next->right);
                    }
                } else {
                    result += "null";
                }
            }
            if (queue.size()) {
                result += ",";
            }
        }
        result += "]";

        return result;
    }

    TreeNode* deserialize(std::string data) {
        if (data == "[]") { return nullptr; }
        TreeNode* root = new TreeNode{};
        auto next = std::find(data.begin(), data.end(), ',');
        root->val = std::stoi(data.substr(1, (next == data.end() ? next - 1 : next) - (data.begin() + 1)));
        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

auto speed=[]() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

TEST_CASE("LC test cases", "[Serialize and Deserialize Binary Tree]") {
    SECTION("Serialize case 1") {
        auto tree = new TreeNode{1, new TreeNode{3, new TreeNode(5), new TreeNode(3)}, new TreeNode{2, nullptr, new TreeNode{9}}};
        std::string expected {"[1,3,2,5,3,null,9]"};
        Codec c;
        REQUIRE(c.serialize(tree) == expected);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
