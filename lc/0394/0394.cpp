// 0394. Decode String
// Problem definition: https://leetcode.com/problems/decode-string/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <string>

class Solution {
public:
    std::string decodeString(std::string s) {
        return "";
    }

private:
    template <typename T>
    void push(T it, std::string& result) {
                
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::string,std::string>> input {
        {"3[a]2[bc]","aaabcbc"},
        {"3[a2[c]]","accaccacc"},
        {"2[abc]3[cd]ef","abcabccdcdcdef"},
        {"abc3[cd]xyz","abccdcdcdxyz"}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.decodeString(testInput) == expected);
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
