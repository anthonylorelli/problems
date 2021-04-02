// 0187. Repeated DNA Sequences
// Problem definition: https://leetcode.com/problems/repeated-dna-sequences/
// Accepted ?
// Rabin-Karp Cf. https://en.wikipedia.org/wiki/Rabin%E2%80%93Karp_algorithm
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    constexpr uint32_t hash(const uint32_t h, const char c) const noexcept { return ((h * c_base) + c) % c_mod; }
    std::vector<std::string> findRepeatedDnaSequences(std::string s) {
        return {};        
    }

private:
    static constexpr uint32_t c_base {256};
    static constexpr uint32_t c_mod {7778777};
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::string,std::vector<std::string>>> input {
        {"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",{{"AAAAACCCCC","CCCCCAAAAA"}},
        {"AAAAAAAAAAAAA",{"AAAAAAAAAA"}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.findRepeatedDnaSequences(testInput) == expected);
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
