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
            bool add_next {false};
            for (int n {0}; n < count; ++n) {
                if (n) { 
                    result += ",";
                }
                TreeNode* next {queue.front()};
                queue.pop();
                if (next) {
                    result += std::to_string(next->val);
                    if (next->left || next->right) {
                        add_next = true;
                    }
                    queue.push(next->left);
                    queue.push(next->right);
                } else {
                    result += "null";
                }
            }
            if (!add_next) {
                break;
            }
            result += ",";
        }
        result += "]";

        return result;
    }

    TreeNode* deserialize(std::string data) {
        if (data == "[]") { return nullptr; }
        auto predicate = [](const char c) { return c == ',' || c == ']'; };
        auto start = data.begin() + 1;
        auto sentinel = std::find_if(start, data.end(), predicate);
        TreeNode* root = new TreeNode{std::stoi(std::string{start, sentinel})};
        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();

            start = sentinel + 1;
            sentinel = std::find_if(start, data.end(), predicate);
            if (sentinel == data.end()) {
                break;
            }
            std::string lval {std::string{start, sentinel}};
            if (lval != "null") {
                current->left = new TreeNode{std::stoi(lval)};
                queue.push(current->left);
            }
            start = sentinel + 1;
            sentinel = std::find_if(start, data.end(), predicate);
            if (sentinel == data.end()) {
                break;
            }
            std::string rval {std::string{start, sentinel}};
            if (rval != "null") {
                current->right = new TreeNode{std::stoi(rval)};
                queue.push(current->right);
            }
        }
        return root;
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
    SECTION("Serialize case 2") {
        auto tree = new TreeNode{2, new TreeNode{1}, nullptr};
        std::string expected {"[2,1,null]"};
        Codec c;
        REQUIRE(c.serialize(tree) == expected);
    }
    SECTION("Serialize case 3") {
        auto tree = new TreeNode{5, new TreeNode{2, new TreeNode{1}, new TreeNode{3}}, new TreeNode{6}};
        std::string expected {"[5,2,6,1,3,null,null]"};
        Codec c;
        REQUIRE(c.serialize(tree) == expected);
    }
    SECTION("Deserialize case 1") {
        std::string expected {"[2,1,3]"};
        Codec c;
        REQUIRE(c.serialize(c.deserialize(expected)) == expected);
    }
    SECTION("Deserialize case 2") {
        std::string expected {"[2,1,3,4,5,6,7]"};
        Codec c;
        REQUIRE(c.serialize(c.deserialize(expected)) == expected);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
