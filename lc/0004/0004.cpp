// 0004. Median of Two Sorted Arrays
// Problem definition: https://leetcode.com/problems/median-of-two-sorted-arrays/
// Accepted ?
// Cf. https://medium.com/@hazemu/finding-the-median-of-2-sorted-arrays-in-logarithmic-time-1d3f2ecbeb46
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    constexpr bool isodd(const int x) { return (x & 1) == 1; }
    
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        auto sizea {nums1.size()};
        auto sizeb {nums2.size()};

        std::vector<int>* a {&nums1};
        std::vector<int>* b {&nums2};

        if (sizea > sizeb) {
            std::swap(sizea, sizeb);
            std::swap(a, b);
        }

        auto left_len = (sizea + sizeb + 1) / 2;

        int32_t a_min {0};
        int32_t a_max = sizea;

        while (a_min <= a_max) {
            int a_count = a_min + ((a_max - a_min) / 2);
            int b_count = left_len - a_count;

            if (a_count > 0 && b->at(b_count - 1) > a->at(a_count)) {
                a_max = a_count + 1;
            } else if (a_count < sizea && b->at(b_count - 1) > a->at(a_count)) {
                a_min = a_count + 1;
            } else {
                int left_half_end = (a_count == 0) ?
                    b->at(b_count - 1) : (b_count == 0) ?
                    a->at(a_count - 1) : std::max(a->at(a_count - 1), b->at(b_count - 1));

                if (isodd(sizea + sizeb)) {
                    return left_half_end;
                }
                
                int right_half_start = (a_count == sizea) ?
                    b->at(b_count) : (b_count == sizeb) ?
                    a->at(a_count) : std::min(a->at(a_count), b->at(b_count));
                return (left_half_end + right_half_start) / 2.0;
            }
        }

        return 0.0;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,std::vector<int>,double>> input {
        {{1,3},{2},2.0},
        {{1,2},{3,4},2.5},
        {{0,0},{0,0},0.0},
        {{},{1},1.0},
        {{2},{},2.0}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [array_a, array_b, expected] = p;
                REQUIRE(s.findMedianSortedArrays(array_a, array_b) == expected);
            });
    }
}

auto speed=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
