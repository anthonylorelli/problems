// 0696. Count Binary Substrings
// Problem definition: https://leetcode.com/problems/count-binary-substrings/
// 2020-02-11

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>

class Solution {
private:
    template <typename T>
    int count(const T& begin, const T& end, const int prev) const {
        if (begin == end) { return 0; }
        const auto next {std::find_if_not(begin, end, [&begin](const auto& n) { return *begin == n; })};
        const int current = next - begin;
        return std::min(prev, current) + count(next, end, current); 
    }

public:
    int countBinarySubstrings(std::string s) {
        if (s.length() == 0) { return 0; }
        return count(s.begin(), s.end(), 0);
    }
};

TEST_CASE("LC test cases", "[Count Binary Substrings]") {
    std::vector<std::pair<std::string,int>> input {
        {"00110011", 6}, {"10101", 4}, {"0011001", 5}, {"1", 0}, {"0", 0}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.countBinarySubstrings(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
