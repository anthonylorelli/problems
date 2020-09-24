// 1286. Iterator for Combination
// Problem definition: https://leetcode.com/problems/iterator-for-combination/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <numeric>
#include <vector>
#include <string>

class CombinationIterator {
public:
    CombinationIterator(std::string characters, int combinationLength) : m_pos{0} {
        std::string current{combinationLength, ' '};
        generate(0, current, characters);
    }
    
    std::string next() {
        return m_answer[m_pos++];
    }
    
    bool hasNext() {
        return m_pos < m_answer.size();
    }

private:
    void generate(const int begin, std::string& current, const std::string& characters) {
        if (begin == current.length()) {
            m_answer.push_back(current);
            return;
        }

        int limit {characters.length() - (current.length() - begin)};
        for (int i = begin; i < limit; ++i) {
            current[begin] = characters[i];
            generate(begin + 1, current, characters);
        }
    }

    std::vector<std::string> m_answer;
    int m_pos;
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

auto speed=[]() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}

TEST_CASE("LC test cases", "[Core]") {
    Solution s;
    SECTION("LC test case 1") {
    }
}
