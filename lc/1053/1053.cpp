// 1053. Previous Permutation With One Swap
// Problem definition: https://leetcode.com/problems/previous-permutation-with-one-swap/
// ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>

bool operator<(const std::vector<int>& lhs, const std::vector<int>& rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

class Solution {
public:
    std::vector<int> prevPermOpt1(std::vector<int>& A) {
        std::vector perm{A};
        std::prev_permutation(perm.begin(), perm.end());
        return perm < A ? perm : A;
    }
};

TEST_CASE("LC test cases", "[Previous Permutation With One Swap]") {
    std::vector<std::pair<std::vector<int>,std::vector<int>>> input {
        {{3,2,1},{3,1,2}}, {{1,1,5},{1,1,5}}, {{1,9,4,6,7},{1,7,4,6,9}}, {{3,1,1,3},{1,3,1,3}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.prevPermOpt1(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
