// 1234. Replace the Substring for Balanced String
// Problem definition: https://leetcode.com/problems/replace-the-substring-for-balanced-string/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>

class Solution {
public:
    int balancedString(std::string s) {
        auto n {s.size() / 4};
        auto start {seek(s.begin(), s.end(), n)};
        auto end {seek(s.rbegin(), s.rend(), n)};
        return s.size() - (start - s.begin()) - (end - s.rbegin());
    }

private:
    inline int& parse(const char c) noexcept {
        return c == 'Q' ? m_q : c == 'R' ? m_r : c == 'W' ? m_w : m_e;
    }

    template <typename T, typename I>
    T seek(T begin, T end, const I n) {
        while (begin < end) {
            int &i {parse(*begin)};
            if (i == n) { return begin; }
            else { i++; }
            begin++;
        }
        return begin;
    }

    int m_q {0};
    int m_r {0};
    int m_w {0};
    int m_e {0};
};

TEST_CASE("LC test cases", "[Replace the Substring for Balanced String]") {
    std::vector<std::pair<std::string,int>> input {
        {{"QWER",0},{"QQWE",1},{"QQQW",2},{"QQQQ",3}}
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
