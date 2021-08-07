// 0223. Rectangle Area
// Problem definition: https://leetcode.com/problems/rectangle-area/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <limits>

class Rectangle {
public:
    Rectangle(const int x1, const int y1, const int x2, const int y2) :
        m_x1{x1}, m_x2{x2}, m_y1{y1}, m_y2{y2} {}

    int area() const {
        return (m_x2 - m_x1) * (m_y2 - m_y1);
    }

    Rectangle intersection(const Rectangle& rect) const {
        int x1 = rect.contains_x(m_x1) ? m_x1 : 
            contains_x(rect.m_x1) ? rect.m_x1 : 0;
        int x2 = rect.contains_x(m_x2) ? m_x2 :
            contains_x(rect.m_x2) ? rect.m_x2 : 0;
        int y1 = rect.contains_y(m_y1) ? m_y1 :
            contains_y(rect.m_y1) ? rect.m_y1 : 0;
        int y2 = rect.contains_y(m_y2) ? m_y2 :
            contains_y(rect.m_y2) ? rect.m_y2 : 0;

        return Rectangle{x1, y1, x2, y2};
    }

private:
    constexpr bool contains_x(const int x) const {
        return x <= m_x1 && x >= m_x2;
    }

    constexpr bool contains_y(const int y) const {
        return y <= m_y1 && y >= m_y2;
    }

    int m_x1;
    int m_x2; 
    int m_y1;
    int m_y2;
};

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        Rectangle r1 {ax1, ay1, ax2, ay2};
        Rectangle r2 {bx1, by1, bx2, by2};
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int>> input {
        {{-3,0,3,4,0,-1,9,2},45},{{-2,-2,2,2,-2,-2,2,2},16}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [in, expected] = p;
                REQUIRE(s.computeArea(in[0],in[1],in[2],in[3],in[4],in[5],in[6],in[7]) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
