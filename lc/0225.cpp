// 0225. Implement Stack Using Queues
// Problem definition: https://leetcode.com/problems/implement-stack-using-queues/
// Accepted 2021-05-06
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <queue>

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() { }
    
    /** Push element x onto stack. */
    void push(int x) {
        m_queue.push(x);
        auto s = m_queue.size();
        while (s > 1) {
            m_queue.push(m_queue.front());
            m_queue.pop();
            s--;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        auto top = m_queue.front();
        m_queue.pop();
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return m_queue.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return m_queue.empty();        
    }

private:
    std::queue<int> m_queue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

// TEST_CASE("LC test cases", "[Core]") {
//     std::vector<std::tuple<std::string,std::vector<std::string>,std::string>> input {
//         {"1s3 PSt",{"step","steps","stripe","stepple"},"steps"},
//         {"1s3 456",{"looks","pest","stew","show"},"pest"},
//         {"Ah71752",{"suggest","letter","of","husband","easy","education","drug","prevent","writer","old"},"husband"},
//         {"iMSlpe4",{"claim","consumer","student","camera","public","never","wonder","simple","thought","use"},"simple"}
//     };

//     SECTION("Test cases") {
//         std::for_each(std::begin(input), std::end(input),
//             [&](auto& p) {
//                 auto& [testInput, words, expected] = p;
//                 REQUIRE(Solution{}.shortestCompletingWord(testInput, words) == expected);
//             });
//     }
// }

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
