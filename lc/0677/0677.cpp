// 0677. Map Sum Pairs
// Problem definition: https://leetcode.com/problems/map-sum-pairs/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() { }
    
    void insert(std::string key, int val) {
        
    }
    
    int sum(std::string prefix) {
        
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    return Catch::Session().run(argc, argv);
    //return execute(std::cin, std::cout);
}

TEST_CASE("", "[Map Sum Pairs]") {
    SECTION("LC test case 1") {
        // Input: insert("apple", 3), Output: Null
        // Input: sum("ap"), Output: 3
        // Input: insert("app", 2), Output: Null
        // Input: sum("ap"), Output: 5
        MapSum ms;
    }
}
