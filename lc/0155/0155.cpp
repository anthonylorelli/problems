// 0155. Min Stack
// Problem definition: https://leetcode.com/problems/min-stack/
// Accepted 2020-11-14
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/listnode.h"
#include "../../inc/serialize.h"

#include <vector>
#include <limits>

class MinStack {
public:
    MinStack() : m_min{std::numeric_limits<int>::max()} {}
    
    void push(int x) {
        m_stack.push_back(x);
        m_min = std::min(m_min, x);     
    }
    
    void pop() {
        m_stack.pop_back();
        m_min = m_stack.size() > 0 ? *std::min_element(m_stack.begin(), m_stack.end()) : 
            std::numeric_limits<int>::max();
    }
    
    int top() {
        return m_stack.back();
    }
    
    int getMin() {
        return m_min;
    }

private:
    std::vector<int> m_stack;
    int m_min;
};

// ["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"]
// [[],[2147483646],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]]

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::tuple<std::vector<int>,int,int>,bool>> input {
        {{{1,2,3,1},3,0}, true},
        {{{1,0,1,1},1,2}, true},
        {{{1,5,9,1,5,9},2,3}, false},
        {{{},0,0}, false},
        {{{1},0,0}, false},
        {{{1,1},1,0}, true},
        {{{1,2},1,0}, false},
        {{{8,7,15,1,6,1,9,15},1,3}, true},
        {{{1,5,9,1,5,9},2,3},false}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                // Solution s;
                // auto& [testInput, expected] = p;
                // auto [input, k, t] = testInput;
                // REQUIRE(s.containsNearbyAlmostDuplicate(input, k, t) == expected);
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
