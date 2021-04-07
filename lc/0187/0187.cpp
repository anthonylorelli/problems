// 0187. Repeated DNA Sequences
// Problem definition: https://leetcode.com/problems/repeated-dna-sequences/
// Accepted ?
// Rabin-Karp Cf. https://en.wikipedia.org/wiki/Rabin%E2%80%93Karp_algorithm
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <string>
#include <vector>
#include <string_view>
#include <unordered_set>
#include <iostream>

constexpr uint32_t pow(const uint32_t exp, const uint32_t base, const uint32_t mod) {
    return exp == 0 ? 1 : (pow(exp - 1, base, mod) * base) % mod;
}

class RollingHash {
public:
    RollingHash(const std::string_view& s, const uint32_t length) : m_s{s}, m_length{length} { 
        // We assume length < s.size()
        uint32_t limit {length - 1};
        while (m_current < limit) {
            m_hash = hash(m_hash, m_s[m_current]);
            ++m_current;
        }
        m_hash = hash(m_hash, m_s[m_current]);
    }

    bool has_next() const noexcept {
        return m_current < m_s.size();
    }

    uint32_t next() noexcept {
        auto cache = m_hash;
        ++m_current;
        if (has_next()) {
            m_hash = (m_hash + c_mod) - ((m_s[m_current - m_length] * c_offset) % c_mod);
            m_hash = hash(m_hash, m_s[m_current]);
        }
        return cache;
    }

private:
    constexpr uint32_t hash(const uint32_t h, const char c) const noexcept { 
        return ((h * c_base) + c) % c_mod; 
    }

    std::string_view m_s;
    const uint32_t m_length;
    uint32_t m_current {0};
    uint32_t m_hash {0};

    static constexpr uint32_t c_base {256};
    static constexpr uint32_t c_mod {7778777};
    static constexpr uint32_t c_offset {pow(9, c_base, c_mod)};
};

class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s) {
        std::vector<std::string> result;
        if (s.size() < 11) {
            return result;
        }
        RollingHash hash(std::string_view{s}, 10);
        std::unordered_set<uint32_t> found;
        while (hash.has_next()) {
            auto current = hash.next();
        }
        return result;
    }
};

// TEST_CASE("LC test cases", "[Core]") {
//     std::vector<std::tuple<std::string,std::vector<std::string>>> input {
//         {"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",{"AAAAACCCCC","CCCCCAAAAA"}},
//         {"AAAAAAAAAAAAA",{"AAAAAAAAAA"}}
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

TEST_CASE("LC test cases", "[RollingHash class unit tests]") {
    SECTION("LC test cases") {
        std::string_view testInput {"AAAAAAAAAAAA"};
        RollingHash hash(testInput, 10);
        auto current = hash.next();
        while (hash.has_next()) {
            auto next = hash.next();
            std::cout << "Current: " << current << " Next: " << next << "\n";
            REQUIRE(current == next);
            current = next;
        }
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
