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

    template <typename It>
    void add_strings(It b1, It e1, It b2, It e2, int32_t carry, std::string& result) {
        int32_t digit {0};
        if (b1 == e1 && b2 == e2) {
            if (carry > 0) {
                result.push_back(carry + '0');
            }
            return;
        }

        int32_t digit_l {0};
        if (b1 != e1) {
            digit_l = *b1 - '0';
            b1++;
        }

        int32_t digit_r {0};
        if (b2 != e2) {
            digit_r = *b2 - '0';
            b2++;
        }

        int32_t sum {carry + digit_l + digit_r};
        add_strings(b1, e1, b2, e2, sum / 10, result);

        result.push_back((sum % 10) + '0');
    }

    std::string add(const std::string& s1, const std::string& s2) {
        std::string result;
        add_strings(s1.rbegin(), s1.rend(), s2.rbegin(), s2.rend(), 0, result);
        return result;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::string,bool>> input {
        {{"112358", true}, {"199100199", true}}
    };

    // SECTION("LC test cases") {
    //     std::for_each(std::begin(input), std::end(input),
    //         [&input](auto& p) {
    //             Solution s;
    //             auto& [testInput, expected] = p;
    //             REQUIRE(s.isAdditiveNumber(testInput) == expected);
    //         });
    // }
    SECTION("Add strings") {
        Solution s;
        std::string s1{"123"};
        std::string s2{"456"};
        REQUIRE(std::string{"579"} == s.add(s1, s2));

        s1 = "1";
        s2 = "999";
        REQUIRE(std::string{"1000"} == s.add(s1, s2));
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
