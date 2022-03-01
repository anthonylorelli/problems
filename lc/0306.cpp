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

    bool isAdditiveSequence(size_t a_start, size_t a_size, size_t b_start, size_t b_size, 
        std::string& num) {
        
    }

    template <typename It>
    void add_strings(It b1, It e1, It b2, It e2, int32_t carry, std::string& result) {
        int32_t digit {0};
        
    }

    std::string add(const std::string& s1, const std::string& s2) {

    }
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
