// 0331. Verify Preorder Serlalization of a Binary Tree
// Problem definition: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>

class Solution {
public:
    int checkTree(const std::string& t, const int i) {
        if (i >= t.size()) { return 0; }

        char c {t[i]};
        int r {i + 2};

        if (c == '#') {
            return r;
        } else if (r >= t.size()) {
            return 0;
        } 
            
        int l {checkTree(t, r)};
        
        if (l >= t.size()) {
            return 0;
        } 
            
        return checkTree(t, l);
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
        {"",true},{"#",true}
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
