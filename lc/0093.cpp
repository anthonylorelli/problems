// 0093. Restore IP Addresses
// Problem definition: https://leetcode.com/problems/restore-ip-addresses/
// Accepted 2021-07-17
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        parse(s.begin(), s.end());
        return m_vec;
    }

    template <typename It, typename End>
    void parse(It begin, End end) {
        auto length = std::distance(begin, end);
        if (length > 12) {
            return;
        }
        if (*begin == '0') {
            parse_second(begin + 1, end, std::string{begin, begin + 1});
            return;
        }
        int32_t tuplet {0};
        for (int32_t i {0}; i < 3 && ((begin + i) != end); ++i) {
            tuplet = (tuplet * 10) + (*(begin + i) - '0');
            if (i < 2 || tuplet <= 255) {
                parse_second(begin + i + 1, end, std::string{begin, begin + i + 1});
            }
        }
    }

    template <typename It, typename End>
    void parse_second(It begin, End end, const std::string& first) {
        auto length = std::distance(begin, end);
        if (length > 9 || length < 3) {
            return;
        }
        if (*begin == '0') {
            parse_third(begin + 1, end, first, std::string{begin, begin + 1});
            return;
        }
        int32_t tuplet {0};
        for (int32_t i {0}; i < 3 && ((begin + i) != end); ++i) {
            tuplet = (tuplet * 10) + (*(begin + i) - '0');
            if (i < 2 || tuplet <= 255) {
                parse_third(begin + i + 1, end, first, std::string{begin, begin + i + 1});
            }
        }
    }

    template <typename It, typename End>
    void parse_third(It begin, End end, const std::string& first, const std::string& second) {
        auto length = std::distance(begin, end);
        if (length > 6 || length < 2) {
            return;
        }
        if (*begin == '0') {
            parse_fourth(begin + 1, end, first, second, std::string{begin, begin + 1});
            return;
        }
        int32_t tuplet {0};
        for (int32_t i {0}; i < 3 && ((begin + i) != end); ++i) {
            tuplet = (tuplet * 10) + (*(begin + i) - '0');
            if (i < 2 || tuplet <= 255) {
                parse_fourth(begin + i + 1, end, first, second, std::string{begin, begin + i + 1});
            }
        }
    }

    template <typename It, typename End>
    void parse_fourth(It begin, End end, const std::string& first, 
        const std::string& second, const std::string& third) {
        auto length = std::distance(begin, end);
        if (length > 3 || length == 0 || ((*begin == '0') && length > 1)) {
            return;
        }
        int tuplet {0};
        for (It b {begin}; b != end; ++b) {
            tuplet = (tuplet * 10) + (*b - '0');
        }
        if (tuplet > 255) {
            return;
        }
        m_vec.push_back(std::string{first}.append(".").append(second).append(".").
            append(third).append(".").append(std::string{begin, end}));
    }

private:
    std::vector<std::string> m_vec;
};

class SolutionStringView {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        parse(s.begin(), s.end());
        return m_vec;
    }

    template <typename It, typename End>
    void parse(It begin, End end) {
        auto length = std::distance(begin, end);
        if (length > 12) {
            return;
        }
        if (*begin == '0') {
            parse_second(begin + 1, end, std::string_view{begin, begin + 1});
            return;
        }
        int32_t tuplet {0};
        for (int32_t i {0}; i < 3 && ((begin + i) != end); ++i) {
            tuplet = (tuplet * 10) + (*(begin + i) - '0');
            if (i < 2 || tuplet <= 255) {
                parse_second(begin + i + 1, end, std::string_view{begin, begin + i + 1});
            }
        }
    }

    template <typename It, typename End>
    void parse_second(It begin, End end, const std::string_view& first) {
        auto length = std::distance(begin, end);
        if (length > 9 || length < 3) {
            return;
        }
        if (*begin == '0') {
            parse_third(begin + 1, end, first, std::string_view{begin, begin + 1});
            return;
        }
        int32_t tuplet {0};
        for (int32_t i {0}; i < 3 && ((begin + i) != end); ++i) {
            tuplet = (tuplet * 10) + (*(begin + i) - '0');
            if (i < 2 || tuplet <= 255) {
                parse_third(begin + i + 1, end, first, std::string_view{begin, begin + i + 1});
            }
        }
    }

    template <typename It, typename End>
    void parse_third(It begin, End end, const std::string_view& first, const std::string_view& second) {
        auto length = std::distance(begin, end);
        if (length > 6 || length < 2) {
            return;
        }
        if (*begin == '0') {
            parse_fourth(begin + 1, end, first, second, std::string_view{begin, begin + 1});
            return;
        }
        int32_t tuplet {0};
        for (int32_t i {0}; i < 3 && ((begin + i) != end); ++i) {
            tuplet = (tuplet * 10) + (*(begin + i) - '0');
            if (i < 2 || tuplet <= 255) {
                parse_fourth(begin + i + 1, end, first, second, std::string_view{begin, begin + i + 1});
            }
        }
    }

    template <typename It, typename End>
    void parse_fourth(It begin, End end, const std::string_view& first, 
        const std::string_view& second, const std::string_view& third) {
        auto length = std::distance(begin, end);
        if (length > 3 || length == 0 || ((*begin == '0') && length > 1)) {
            return;
        }
        int tuplet {0};
        for (It b {begin}; b != end; ++b) {
            tuplet = (tuplet * 10) + (*begin - '0');
        }
        if (tuplet > 255) {
            return;
        }
        m_vec.push_back(std::string{first}.append(".").append(second).append(".").
            append(third).append(".").append(std::string_view{begin, end}));
    }

private:
    std::vector<std::string> m_vec;
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::string,std::vector<std::string>>> input {
        {"25525511135",{"255.255.11.135","255.255.111.35"}},
        {"0000",{"0.0.0.0"}},
        {"010010",{"0.10.0.10","0.100.1.0"}},
        {"101023",{"1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"}},
        {"000256",{}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.restoreIpAddresses(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
