// 0232. Implement Queue Using Stacks
// Problem definition: https://leetcode.com/problems/implement-queue-using-stacks/
// Accepted 2021-01-16
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <stack>

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() { }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (m_back.empty() && !m_front.empty()) {
            copy(m_front, m_back);
        }
        m_back.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (m_front.empty() && !m_back.empty()) {
            copy(m_back, m_front);
        }
        int top = m_front.top();
        m_front.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        if (m_front.empty() && !m_back.empty()) {
            copy(m_back, m_front);
        }
        return m_front.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return m_front.empty() && m_back.empty();        
    }

private:
    void copy(std::stack<int>& source, std::stack<int>& dest) {
        while (!source.empty()) {
            dest.push(source.top());
            source.pop();
        }
    }

    std::stack<int> m_front;
    std::stack<int> m_back;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

// TEST_CASE("LC test cases", "[Core]") {
//     std::vector<std::tuple<std::vector<int>,int>> input {
//         {{3,4,2},6},
//         {{2,2,3,3,3,4},9}
//     };

//     SECTION("LC test cases") {
//         std::for_each(std::begin(input), std::end(input),
//             [&input](auto& p) {
//                 Solution s;
//                 auto& [testInput, expected] = p;
//                 REQUIRE(s.deleteAndEarn(testInput) == expected);
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
