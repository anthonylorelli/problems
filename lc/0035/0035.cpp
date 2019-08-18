// 0035. Search Insert Position
// Problem definition: https://leetcode.com/problems/search-insert-position/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        return 0;        
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}

TEST_CASE("LC test cases", "[Search Insert Position]") {
    Solution s;
    SECTION("LC test case 1") {
    }
}
