// 1234. Replace the Substring for Balanced String
// Problem definition: https://leetcode.com/problems/replace-the-substring-for-balanced-string/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>
#include <unordered_map>

class Solution {
public:
    int balancedString(std::string s) {
        auto n {s.size() / 4};
        auto start {seek(s.begin(), s.end(), n)};
        auto end {seek(s.rbegin(), s.rend(), n)};
        auto min {s.size() - (start - s.begin()) - (end - s.rbegin())};
        while (start >= s.begin()) {
            m_map[*start]--;
            start--;
            while (end < s.rend() && m_map[*end] < n) {
                m_map[*end]++;
                end++;
                min = std::min(min, s.size() - (start - s.begin()) - (end - s.rbegin()));
            }            
        }
        return min;
    }

private:
    template <typename T, typename I>
    T seek(T begin, T end, const I n) {
        while (begin < end) {
            if (m_map[*begin] == n) { return begin; }
            else { m_map[*begin]++; }
            begin++;
        }
        return begin;
    }

    std::unordered_map<char,int> m_map {{'Q',0},{'W',0},{'E',0},{'R',0}};
};

TEST_CASE("LC test cases", "[Replace the Substring for Balanced String]") {
    std::vector<std::pair<std::string,int>> input {
        {{"QWER",0},{"QQWE",1},{"QQQW",2},{"QQQQ",3},{"QERWRRWR",2}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [input, output] = p;
                REQUIRE(s.balancedString(input) == output);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
