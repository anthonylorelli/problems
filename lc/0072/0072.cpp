// 72. Edit Distance
// Problem definition: https://leetcode.com/problems/edit-distance/
// Accepted ?

/* 
Given two words word1 and word2, find the minimum number of operations required 
to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 */

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <string>
#include <vector>

struct Cell {
    int cost;
    int parent;
};

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        const size_t max{std::max(word1.length(), word2.length()) + 1};
        std::vector<std::vector<Cell>> m(max, std::vector<Cell>(max));

        
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    return Catch::Session().run(argc, argv);
    //return execute(std::cin, std::cout);
}

TEST_CASE("", "[Edit Distance]") {
    SECTION("") {
        REQUIRE(true);
    }
}
