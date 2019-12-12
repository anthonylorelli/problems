// 1109. Corporate Flight Bookings
// Problem definition: https://leetcode.com/problems/corporate-flight-bookings/
// Accepted 2019-12-11
// Cf. https://en.wikipedia.org/wiki/Interval_tree

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>
#include <map>
#include <memory>

class IntervalTree {
public:
    IntervalTree(const int midpoint, const int increment = 0) : 
        m_midpoint{ midpoint }, m_increment{ increment } {}

    void insert(const int start, const int end, const int value) {
        if (start <= m_midpoint && m_midpoint <= end) {
            m_lower[start] += value;
            m_upper[end] += value;
        } else if (end < m_midpoint) {
            if (!m_lhs) { m_lhs = std::make_unique<IntervalTree>(m_midpoint - m_increment, m_increment > 1 ? m_increment / 2 : 1); }
            m_lhs->insert(start, end, value);
        } else { // start > m_midpoint 
            if (!m_rhs) { m_rhs = std::make_unique<IntervalTree>(m_midpoint + m_increment, m_increment > 1 ? m_increment / 2 : 1); }
            m_rhs->insert(start, end, value);
        }
    }

    int at(const int index) const {
        int value {0};
        if (index <= m_midpoint) {
            auto range {m_lower.begin()};
            while (range != m_lower.end() && range->first <= index) { 
                value += range->second;
                range++;
            }
            if (m_lhs) { value += m_lhs->at(index); }
        } else { // index > m_midpoint
            auto range {m_upper.begin()};
            while (range != m_upper.end() && range->first >= index) { 
                value += range->second;
                range++;
            }
            if (m_rhs) { value += m_rhs->at(index); }
        }
        return value;
    }

private:
    int m_midpoint;
    int m_increment;
    std::unique_ptr<IntervalTree> m_rhs;
    std::unique_ptr<IntervalTree> m_lhs;
    std::map<int,int> m_lower;
    std::map<int,int,std::greater<int>> m_upper;
};

class Solution {
public:
    std::vector<int> corpFlightBookings(std::vector<std::vector<int>>& bookings, int n) {
        std::vector<int> seats(n, 0);
        for (const auto& flights : bookings) {
            seats[flights[0]-1] += flights[2];
            if (flights[1] < n) { seats[flights[1]] -= flights[2]; }
        }

        int increment {0};
        std::transform(seats.begin(), seats.end(), seats.begin(), [&increment](const auto n) {
            auto sum {n + increment};
            return increment = sum;
        });

        return seats;
    }
};

TEST_CASE("LC test cases", "[Corporate Flight Bookings]") {
    std::vector<std::pair<std::pair<std::vector<std::vector<int>>,int>,std::vector<int>>> input {
        {{{{1,2,10},{2,3,20},{2,5,25}},5},{10,55,45,25,25}},
        {{{{1,1,10},{1,1,20},{1,1,25}},1},{55}},
        {{{{1,1,10},{3,3,20},{5,5,25}},5},{10,0,20,0,25}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.corpFlightBookings(testInput.first, testInput.second) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
