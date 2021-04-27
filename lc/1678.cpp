// 1678. Goal Parser
// Problem definition: https://leetcode.com/problems/goal-parser-interpretation/
// Accepted 2021-04-25
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <string>

class Solution {
public:
    std::string interpret(std::string command) {
        std::string result;
        interpret(command.begin(), command.end(), result);
        return result;
    }

    template <typename T>
    void interpret(T first, T last, std::string& result) {
        if (first == last) {
            return;
        }

        switch (*first++) {
        case 'G':
            result.push_back('G');
            interpret(first, last, result);
            break;
        case '(':
            interpret_paren(first, last, result);
            break;
        }
    }

    template <typename T>
    void interpret_paren(T& first, T& last, std::string& result) {
        switch (*first++) {
        case ')':
            result.push_back('o');
            break;
        default:
            result += "al";
            first += 2;
        }
        interpret(first, last, result);
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::string,std::string>> input {
        {"G()(al)","Goal"},{"G()()()()(al)","Gooooal"},{"(al)G(al)()()G","alGalooG"}
    };

    SECTION("Test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&](auto& p) {
                auto& [testInput, expected] = p;
                REQUIRE(Solution{}.interpret(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
