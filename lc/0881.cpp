// 0881. Boats to Save People
// Problem definition: https://leetcode.com/problems/boats-to-save-people/
// 2020-02-14

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>
#include <queue>

class Solution {
private:
    void insert(const int person, const int limit, std::priority_queue<int>& boats) const {
        if (!boats.empty() && boats.top() >= person) {
            boats.pop();
            boats.push(0);
        } else {
            boats.push(limit - person);
        }
    }

public:
    int numRescueBoats(std::vector<int>& people, int limit) {
        std::sort(people.begin(), people.end(), std::greater<int>());
        std::priority_queue<int> boats;
        for (const auto p : people) {
            insert(p, limit, boats);
        }
        return boats.size();
    }
};

TEST_CASE("LC test cases", "[Boats to Save People]") {
    std::vector<std::pair<std::pair<std::vector<int>,int>,int>> input {
        {{{1,2},3},1}, {{{3,2,2,1},3},3}, {{{3,5,3,4},5},4}, {{{5,1,4,2},6},2}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.numRescueBoats(testInput.first, testInput.second) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
