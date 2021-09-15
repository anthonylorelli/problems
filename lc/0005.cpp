// 0005. Longest Palindromic Substring
// Problem definition: https://leetcode.com/problems/longest-palindromic-substring/
// Accepted 2019-09-30

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>
#include <algorithm>
#include <vector>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.length() == 0) {
            return "";
        }

        std::string s2 {add_boundaries(s)};
        std::vector<int> p(s2.length());

        int c {0}, r {0}, m {0}, n {0};

        for (int i = 1; i < s2.length(); ++i) {
            if (i > r) {
                p[i] = 0; m = i - 1; n = i + 1;
            } else {
                int i2 = c * 2 - i;
                if (p[i2] < (r - i - 1)) {
                    p[i] = p[i2];
                    m = -1;
                } else {
                    p[i] = r - i;
                    n = r + 1; m = i * 2 - n;
                }
            }
            while (m >= 0 && n < s2.length() && s2[m] == s2[n]) {
                p[i]++; m--; n++;
            }
            if ((i + p[i]) > r) {
                c = i; r = i + p[i];
            }
        }
        size_t len {0}; c = 0;
        for (int i {1}; i < s2.length(); ++i) {
            if (len < p[i]) {
                len = p[i]; c = i;
            }
        }

        size_t offset {c - len};
        size_t size {c + len + 1 - offset};
        std::string s3 {s2.substr(offset, size)};
        return remove_boundaries(s3);
    }

    std::string add_boundaries(const std::string& s) {
        std::string sp;
        if (s.length() == 0) {
            sp = "||";
            return std::move(sp);
        }

        sp.resize((s.length() * 2) + 1);
        for (size_t i {0}; i < (sp.length() - 1); i += 2) {
            sp[i] = '|';
            sp[i+1] = s[i/2];
        }
        sp[sp.length() - 1] = '|';
        return std::move(sp);
    }

    std::string remove_boundaries(const std::string& s) {
        std::string sp;
        if (s.length() < 3) {
            return std::move(sp);
        }

        sp.resize((s.length() - 1)/2);
        for (size_t i {0}; i < sp.length(); ++i) {
            sp[i] = s[(i * 2) + 1];
        }
        return std::move(sp);
    }
};

TEST_CASE("LC test cases", "[Longest Palindromic Substring]") {
    Solution s;
    std::vector<std::pair<std::string,std::string>> input {
        {"",""}, {"babad","bab"}, {"cbbd","bb"}, {"aaaaaaa", "aaaaaaa"}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&s, &input](auto& p) { 
                REQUIRE(s.longestPalindrome(p.first) == p.second); 
            });
    }
}

TEST_CASE("Local test cases", "[Longest Palindromic Substring]") {
	Solution s;

	SECTION("Add boundaries") {
		std::vector<std::pair<std::string, std::string>> input{
			{"bab","|b|a|b|"}, {"d","|d|"}, {"","||"}
		};
		std::for_each(std::begin(input), std::end(input),
			[&s, &input](auto& p) {
				REQUIRE(s.add_boundaries(p.first) == p.second);
			});
	}
	SECTION("Remove boundaries") {
		std::vector<std::pair<std::string, std::string>> input{
			{"|b|a|b|", "bab"}, {"|d|", "d"}, {"||", ""}
		};
		std::for_each(std::begin(input), std::end(input),
			[&s, &input](auto& p) {
				REQUIRE(s.remove_boundaries(p.first) == p.second);
			});
	}
}


int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
