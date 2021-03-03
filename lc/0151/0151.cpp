// 0151. Reverse Words in a String
// Problem definition: https://leetcode.com/problems/reverse-words-in-a-string/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <string>
#include <iterator>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::string result;
        bool isw{false};
        std::copy_if(s.rbegin(), s.rend(), std::back_inserter(result), [&isw](const auto c) {
            bool prevws = isw;
            isw = static_cast<bool>(std::isspace(c));
            return !(prevws && isw);
        });
        std::reverse(result.begin(), result.end());
        return result;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::string,std::string>> input {
        {"the sky is blue","blue is sky the"},
        {"  hello world  ","world hello"},
        {"a good   example","example good a"},
        {"  Bob    Loves  Alice   ","Alice Loves Bob"},
        {"Alice does not even like bob","bob like even not does Alice"}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.reverseWords(testInput) == expected);
            });
    }
}

auto speed=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
