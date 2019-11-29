// 0844. Backspace String Compare
// Problem definition: https://leetcode.com/problems/backspace-string-compare/
// Accepted 2019-11-29

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>

class Solution {
public:
    std::string filter(const std::string& s) const {
        std::string sp;
        for (const auto c : s) {
            if (c == '#') {
                if (!sp.empty()) { sp.pop_back(); }
            } else {
                sp.push_back(c);
            }
        }
        return sp;
    }

    bool backspaceCompare(std::string S, std::string T) {
        std::string sp{filter(S)}, tp{filter(T)};
        return sp == tp;
    }
};

TEST_CASE("LC test cases", "[Backspace String Compare]") {
    Solution s;
    std::vector<std::pair<std::pair<std::string,std::string>,bool>> input {
        {{{"ab#c","ad#c"},true},{{"ab##","c#d#"},true},{{"a##c","#a#c"},true},
        {{"a#c","b"},false},{{"###",""},true},{{"bbb####b","b"},true}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&s, &input](auto& p) { 
                auto& [S, T] = p.first;
                REQUIRE(s.backspaceCompare(S, T) == p.second); 
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
