// 0394. Decode String
// Problem definition: https://leetcode.com/problems/decode-string/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <string>
#include <iterator>

class Solution {
public:
    std::string decodeString(std::string s) {
        if (s.empty()) { return ""; }
        return decode(s.begin(), s.end());
    }

private:
    template <typename T>
    std::string decode(T begin, T end) {
        std::string result;
        std::string::iterator next;
        while ((next = std::find_if(begin, end, [](const auto c) {
                return std::isdigit(c) || c == ']';
            })) != end) {
            std::copy(begin, next, std::back_inserter(result));
            auto open_bracket = std::find(next + 1, end, '[');
            int count = std::stoi(std::string{next, open_bracket});
            std::string sub = decode(open_bracket + 1, end);
        }
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
