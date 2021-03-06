// 1720. Decode XORed Array
// Problem definition: https://leetcode.com/problems/decode-xored-array/
// Accepted 2021-04-27
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> decode(std::vector<int>& encoded, int first) {
        std::vector<int> result(encoded.size() + 1, first);
        std::transform(encoded.begin(), encoded.end(), result.begin(), result.begin() + 1, 
            [](const auto n1, const auto n2) { return n1 ^ n2; });
        return result;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int,std::vector<int>>> input {
        {{1,2,3},1,{1,0,2,1}},{{6,2,7,3},4,{4,2,0,7,4}}
    };

    SECTION("Test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&](auto& p) {
                auto& [testInput, first, expected] = p;
                REQUIRE(Solution{}.decode(testInput, first) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
