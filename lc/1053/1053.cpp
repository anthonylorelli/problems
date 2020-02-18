// 1053. Previous Permutation With One Swap
// Problem definition: https://leetcode.com/problems/previous-permutation-with-one-swap/
// 2020-02-17

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
private:
    template <typename T>
    auto max_element_under_n(const T& begin, const T& end, const int n) {
        auto max {end};
        auto predicate = [&n](const auto i) { return i < n; };
        for (auto next = std::find_if(begin, end, predicate); next != end;
            next = std::find_if(next + 1, end, predicate)) {
            max = max == end ? next : *next > *max ? next : max;
        }
        return max;
    }

public:
    std::vector<int> prevPermOpt1(std::vector<int>& A) {
        for (auto b {A.rbegin()}; b != A.rend(); ++b) {
            auto offset {A.rend() - b};
            auto max = max_element_under_n(A.begin() + offset, A.end(), *b);
            std::cout << "Max found: " << (max == A.end() ? 0 : *max) << "\n";
            // int* max {nullptr};
            // std::for_each(A.begin() + offset, A.end(), [&b, &max](auto& n) {
            //     if (n < *b && (!max || n > *max)) { max = &n; } 
            // });

            // auto max {A.end()};
            // auto predicate = [&b](const auto n) { return n < *b; };
            // auto next = std::find_if(A.begin() + offset, A.end(), predicate);
            // while (next != A.end()) {
            //     max = max == A.end() ? next : *next > *max ? next : max;
            //     next = std::find_if(next + 1, A.end(), predicate);
            // }
            //if (max) {
            if (max != A.end()) {
                std::iter_swap(b, max);
                break;
            }
        }
        return A;
    }
};

TEST_CASE("LC test cases", "[Previous Permutation With One Swap]") {
    std::vector<std::pair<std::vector<int>,std::vector<int>>> input {
        {{3,2,1},{3,1,2}}, {{1,1,5},{1,1,5}}, {{1,9,4,6,7},{1,7,4,6,9}}, {{3,1,1,3},{1,3,1,3}},
        {{1},{1}},{{1,1},{1,1}},
        {{6,1,5,9,1,1,9,7,7,9,7,6,2,7,3,4,5,1,7,6,3,5,3,1,4,7,1,1,8,8,9,1,9,5,1,6,5,4,7,3,2,7,4,9,7,6,2,5,7,4,3,7,5,5,4,4,2,1,3,1,6,4,8,7,5,9,3,1,4,4,7,5,3,7,2,4,4,8,5,4,8,1,1,3,4,3,5,4,8,1,5,4,9,8,4,5,3,1,1,3},
         {6,1,5,9,1,1,9,7,7,9,7,6,2,7,3,4,5,1,7,6,3,5,3,1,4,7,1,1,8,8,9,1,9,5,1,6,5,4,7,3,2,7,4,9,7,6,2,5,7,4,3,7,5,5,4,4,2,1,3,1,6,4,8,7,5,9,3,1,4,4,7,5,3,7,2,4,4,8,5,4,8,1,1,3,4,3,5,4,8,1,5,4,9,8,4,5,1,3,1,3}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.prevPermOpt1(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
