// 771. Jewels and Stones
// Problem definition: https://leetcode.com/problems/jewels-and-stones/
// Accepted 2019-07-01

// You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  
// Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.
//
// The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so
// "a" is considered a different type of stone from "A".
//
// Example 1:
//
// Input: J = "aA", S = "aAAbbbb"
// Output: 3
// Example 2:
// 
// Input: J = "z", S = "ZZ"
// Output: 0
// Note:
//
// S and J will consist of letters and have length at most 50.
// The characters in J are distinct.

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <unordered_map>
#include <string>

class Solution {
public:
    int numJewelsInStones(std::string J, std::string S) {
        std::unordered_map<char,bool> jewels;
        for (const auto& c : J) {
            jewels[c] = true;
        }

        int result{0};
        for (const auto& c : S) {
            if (jewels.count(c) == 1) { result++; }
        }

        return result;
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    return Catch::Session().run(argc, argv);
    //return execute(std::cin, std::cout);
}

TEST_CASE("First input", "[Jewels and Stones]") {
    std::string J{"aA"};
    std::string S{"aAAbbbbb"};
    Solution s;
    REQUIRE(s.numJewelsInStones(J, S) == 3);
}

TEST_CASE("Second input", "[Jewels and Stones]") {
    std::string J{"z"};
    std::string S{"ZZ"};
    Solution s;
    REQUIRE(s.numJewelsInStones(J, S) == 0);
}
