// 0331. Verify Preorder Serlalization of a Binary Tree
// Problem definition: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
// Accepted 2019-10-16

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>
#include <cctype>

class Solution {
public:
    int eatNumber(const std::string& t, const int i) {
        int j {i};
        while (std::isdigit(t[j])) { ++j; }
        return j + 1;
    }

    int checkTree(const std::string& t, const int i) {
        if (i >= t.size()) { return 0; }

        char c {t[i]};
        int right {i};

        if (c == '#') {
            return right + 2;
        } else {
            right = eatNumber(t, right);
        }
        
        if (right >= t.size()) {
            return 0;
        } 
            
        int left {checkTree(t, right)};
        
        if (left >= t.size() || left == 0) {
            return 0;
        } 
            
        return checkTree(t, left);
    }

    bool isValidSerialization(std::string preorder) {
        if (preorder.size() == 0) { return true; }
        int result {checkTree(preorder, 0)};
        return !(result == 0 || result < preorder.size());
    }
};

TEST_CASE("LC test cases", "[Verify Preorder Serlalization of a Binary Tree]") {
    Solution s;
    std::vector<std::pair<std::string,bool>> input {
        {"9,3,4,#,#,1,#,#,2,#,6,#,#",true},{"1,#",false},{"9,#,#,1",false},
        {"",true},{"#",true},{"1,#,#",true},{"3,#,3",false},{"4,3,#",false},
        {"93,333,411,#,#,1,#,#,20,#,612123,#,#",true},{"9080,#,#",true}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&s, &input](auto& p) { 
                REQUIRE(s.isValidSerialization(p.first) == p.second); 
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
