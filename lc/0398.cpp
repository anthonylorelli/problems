// 0398. Random Pick Index
// Problem definition: https://leetcode.com/problems/random-pick-index/
// Accepted 2021-04-12
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <random>
#include <unordered_map>

class Solution {
public:
    Solution(std::vector<int>& nums) : m_rd{}, m_gen{m_rd()} {
        for (int i {0}; i < nums.size(); ++i) {
            m_map[nums[i]].push_back(i);
        }        
    }
    
    int pick(int target) {
        const auto& vec {m_map[target]};
        const int end = vec.size() - 1;
        std::uniform_int_distribution distrib(0, end);
        return vec[distrib(m_gen)];
    }

private:
    std::random_device m_rd;
    std::mt19937 m_gen;
    std::unordered_map<int,std::vector<int>> m_map;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

// TEST_CASE("LC test cases", "[Core]") {
//     std::vector<std::tuple<std::string,std::vector<std::string>>> input {
//     };

//     SECTION("LC test cases") {
//         std::for_each(std::begin(input), std::end(input),
//             [&input](auto& p) {
//                 Solution s;
//                 auto& [testInput, expected] = p;
//                 REQUIRE(s.findRepeatedDnaSequences(testInput) == expected);
//             });
//     }
// }

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
