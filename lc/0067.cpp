// 0067. Add Binary
// Problem definition: https://leetcode.com/problems/add-binary/
// Accepted 2021-09-24
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        auto ait = a.rbegin();
        auto bit = b.rbegin();
        int carry {0};
        std::string result;
        while (ait != a.rend() || bit != b.rend() || carry != 0) {
            if (ait != a.rend() && *ait == '1') { ++carry; }
            if (bit != b.rend() && *bit == '1') { ++carry; }
            result.push_back(carry % 2 == 1 ? '1' : '0');
            carry /= 2;
            if (ait != a.rend()) { ait++; }
            if (bit != b.rend()) { bit++; }
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::string,std::string,std::string>> input {
        {"11","1","100"},{"1010","1011","10101"}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, b, expected] = p;
                REQUIRE(s.addBinary(testInput, b) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
