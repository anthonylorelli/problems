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
    CombinationIterator(std::string characters, int combinationLength) : 
        m_chars{characters}, m_next(combinationLength), m_index{combinationLength - 1} {
        std::iota(m_next.begin(), m_next.end(), 0);
    }
    
    std::string next() {
    }
    
    bool hasNext() {
        return false;
    }

private:
    void choose() {
        if ()
    }

    std::vector<int> m_next;
    std::string m_chars;
    int m_index;
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
