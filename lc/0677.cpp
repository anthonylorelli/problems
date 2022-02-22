// 0677. Map Sum Pairs
// Problem definition: https://leetcode.com/problems/map-sum-pairs/
// Accepted 2019-07-16

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <map>
#include <string>

class MapSum {
private:
    std::map<std::string,int> m_map;

public:
    /** Initialize your data structure here. */
    MapSum() { }
    
    void insert(std::string key, int val) {
        m_map[key] = val;
    }
    
    int sum(std::string prefix) {
        int tally {0};
        auto lb {std::lower_bound(m_map.cbegin(), m_map.cend(), prefix, 
            [](const std::pair<std::string,int>& v1, const std::string& v2) { return v1.first < v2; })};
        auto end {std::find_if_not(lb, m_map.cend(), 
            [&prefix](const std::pair<std::string,int>& p) { return p.first.compare(0, prefix.size(), prefix, 0, prefix.size()) == 0; })};
        std::for_each(lb, end, [&tally](const std::pair<std::string,int>& p) { tally += p.second; });

        return tally;
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
        REQUIRE(std::string("apple") >= std::string("ap"));
        MapSum ms;
        ms.insert("apple", 3);
        REQUIRE(ms.sum("ap") == 3);
        ms.insert("app", 2);
        REQUIRE(ms.sum("ap") == 5);
        ms.insert("ap", 10);
        REQUIRE(ms.sum("ap") == 15);
        REQUIRE(ms.sum("lo") == 0);
    }
}
