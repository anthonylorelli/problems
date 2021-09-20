// 0043. Multiply Strings
// Problem definition: 
// Accepted 2021-09-19
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/listnode.h"

#include <algorithm>
#include <vector>
#include <string>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        std::vector<int> result(num1.size() + num2.size(), 0);
        for (int32_t i = num1.size() - 1; i >= 0; --i) {
            for (int32_t j = num2.size() - 1; j >= 0; --j) {
                result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                result[i + j] += result[i + j + 1] / 10;
                result[i + j + 1] %= 10;
            }
        }

        std::string final;
        std::transform(std::find_if(result.begin(), result.end(), [](const auto n) { return n > 0; }),
            result.end(), std::back_inserter(final), [](const auto n) { return n + '0'; });
        return final;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::string,std::string,std::string>> input {
        {"2", "3", "6"}, {"123", "456", "56088"}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, input2, expected] = p;
                REQUIRE(s.multiply(testInput, input2) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
