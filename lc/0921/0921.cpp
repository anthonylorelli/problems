// 0921. Minimum Add to Make Parentheses Valid
// Problem definition: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>

class Solution {
public:
    template <typename T>
    int minAddClose(const T& begin, const T& end, int sum) {
        if (begin != end) {
            switch (*begin) {
            case '(':
                return std::abs(sum) + minAddOpen(begin + 1, end, 1);
                break;
            case ')':
                return minAddClose(begin + 1, end, sum - 1);
                break;
            }
        }

        return std::abs(sum);
    }

    template <typename T>
    int minAddOpen(const T& begin, const T& end, int sum) {
        if (begin != end) {
            switch (*begin) {
            case '(':
                return minAddOpen(begin + 1, end, sum + 1);
                break;
            case ')':
                return minAddClose(begin + 1, end, sum - 1);
                break;
            }
        }

        return std::abs(sum);
    }

    int minAddToMakeValid(std::string S) {
        return std::abs(minAddOpen(S.begin(), S.end(), 0));        
    }
};

TEST_CASE("LC test cases", "[Guess Number Higher or Lower II]") {
    Solution s;
    std::vector<std::pair<std::string,int>> input {
        {{"())",1},{"(((",3},{"()",0},{"()))((",4},{"",0},{"(",1},{")",1},{"(()())((",2}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&s, &input](auto& p) { 
                REQUIRE(s.minAddToMakeValid(p.first) == p.second); 
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
