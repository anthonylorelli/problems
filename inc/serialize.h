#pragma once

#include <queue>
#include <string>
#include "treenode.h"

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
