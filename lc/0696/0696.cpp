// 0696. Count Binary Substrings
// Problem definition: https://leetcode.com/problems/count-binary-substrings/
// ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>

class Solution {
private:
    template <typename T>
    int count(const T& begin, const T& end, int prev) {
        if (begin == end) { return 0; }
        int current = std::count(begin, end, *begin);
        int min {std::min(prev, current)};
        return ((min * 2) / 2) + count(begin + current, end, current); 
    }

public:
    int countBinarySubstrings(std::string s) {
        if (s.length() == 0) { return 0; }
        return count(s.begin(), s.end(), 0);
    }
};

TEST_CASE("LC test cases", "[Count Binary Substrings]") {
    std::vector<std::pair<std::string,int>> input {
        {"00110011", 6}, {"10101", 4}
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
