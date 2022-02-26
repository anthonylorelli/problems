// 0306. Additive Number
// Problem definition: https://leetcode.com/problems/additive-number/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <string>

class Solution {
public:
    bool isAdditiveNumber(std::string num) {
        if (num.length() < 3) { return false; }

        return false;
    }

    

private:
    size_t m_a_start;
    size_t m_b_start;
    size_t m_a_len;
    size_t m_b_len;
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::string,bool>> input {
        {{"112358", true}, {"199100199", true}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.isAdditiveNumber(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}