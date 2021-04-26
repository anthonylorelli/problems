// 1528. Shuffle String
// Problem definition: https://leetcode.com/problems/shuffle-string/
// Accepted 2021-04-25
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <numeric>
#include <vector>
#include <string>

class Solution {
public:
    std::string restoreString(std::string s, std::vector<int>& indices) {
        std::string result(s.length(), ' ');
        implicit_transform(s.begin(), s.end(), indices.begin(),
            [&](const auto c, const auto n) { result[n] = c; });
        return result;
    }

    template <typename T, typename U, typename V>
    void implicit_transform(T first1, T last1, U first2, const V& binary_op) {
        while (first1 != last1) {
            binary_op(*first1++, *first2++);
        }
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::string,std::vector<int>,std::string>> input {
        {"codeleet",{4,5,6,7,0,2,1,3},"leetcode"}, {"abc",{0,1,2},"abc"},
        {"aiohn",{3,1,4,2,0},"nihao"}, {"aaiougrt",{4,0,2,6,7,3,1,5},"arigatou"},
        {"art",{1,0,2},"rat"}
    };

    SECTION("Test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&](auto& p) {
                auto& [testInput, shuffle, expected] = p;
                REQUIRE(Solution{}.restoreString(testInput, shuffle) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
