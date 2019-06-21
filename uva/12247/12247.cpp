// Jollo
// Problem definition: https://uva.onlinejudge.org/external/122/12247.pdf
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../catch/catch.hpp"

#include <algorithm>
#include <array>
#include <iostream>
#include <set>

class JolloGame
{
public:
    JolloGame(std::istream& i) {
        for (auto& n : m_sister) { i >> n; m_cards.emplace(n); }
        for (auto& n : m_son) { i >> n; m_cards.emplace(n); }
        std::sort(m_sister.begin(), m_sister.end());
        std::sort(m_son.begin(), m_son.end());
    }

    const int card() const {
        // Both cards are smaller or both are larger
        if (m_son[1] < m_sister[2] && m_son[0] < m_sister[1])  {
            return noAnswer;
        } else if (m_son[1] < m_sister[2] && m_son[0] > m_sister[1]) {
            return (m_son[0] > (m_sister[1] + 1)) ? next(m_sister[1]) : next(m_sister[0]);
        } else if (m_son[1] > m_sister[2] && m_son[0] < m_sister[1]) {
            return next(m_sister[1]);
        } else if (m_son[1] > m_sister[2] && m_son[0] > m_sister[1]) {
            // return lowest available card in deck
            return next(m_sister[0]);
        }
        return noAnswer;
    }

    static constexpr int noAnswer{-1};

    const int next(const int n) const {
        int next{n};
        while (m_cards.find(next) != m_cards.end()) { ++next; }
        return next;
    }

private:
    std::array<int,3> m_sister;
    std::array<int,2> m_son;
    std::set<int> m_cards;
};

int execute(std::istream& in, std::ostream& out) {
    return 0;
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    return Catch::Session().run(argc, argv);
    //return execute(std::cin, std::cout);
}

TEST_CASE("Card tests", "[Jollo]") {
    SECTION("Both greater than") {
        std::istringstream i{"1 2 3 4 5"};
        JolloGame g{i};
        REQUIRE(g.card() == 6);
    }
    SECTION("Both less than") {
        std::istringstream i{"4 5 3 1 2"};
        JolloGame g{i};
        REQUIRE(g.card() == JolloGame::noAnswer);
    }
    SECTION("First sample input") {
        std::istringstream i{"28 51 29 50 52"};
        JolloGame g{i};
        REQUIRE(g.card() == 30);
    }
    SECTION("Second sample input") {
        std::istringstream i{"50 26 19 10 27"};
        JolloGame g{i};
        REQUIRE(g.card() == JolloGame::noAnswer);
    }
    SECTION("Third sample input") {
        std::istringstream i{"10 20 30 24 26"};
        JolloGame g{i};
        REQUIRE(g.card() == 21);
    }
    SECTION("Fourth sample input") {
        std::istringstream i{"46 48 49 47 50"};
        JolloGame g{i};
        REQUIRE(g.card() == 51);
    }
}

TEST_CASE("Next tests", "[Jollo]") {
    SECTION("Simple") {
        std::istringstream i{"1 3 5 7 9"};
        JolloGame g{i};
        REQUIRE(g.next(1) == 2);
        REQUIRE(g.next(2) == 2);
        REQUIRE(g.next(3) == 4);
        REQUIRE(g.next(4) == 4);
        REQUIRE(g.next(5) == 6);
        REQUIRE(g.next(6) == 6);
        REQUIRE(g.next(7) == 8);
        REQUIRE(g.next(8) == 8);
        REQUIRE(g.next(9) == 10);
        REQUIRE(g.next(0) == 0);
        REQUIRE(g.next(10) == 10);
    }
    SECTION("Sequence") {
        std::istringstream i{"1 2 3 4 7"};
        JolloGame g{i};
        REQUIRE(g.next(1) == 5);
        REQUIRE(g.next(2) == 5);
        REQUIRE(g.next(3) == 5);
        REQUIRE(g.next(4) == 5);
        REQUIRE(g.next(5) == 5);
        REQUIRE(g.next(1) == 5);
    }
}

TEST_CASE("Execute unit tests", "[Jollo]") {
    std::istringstream i{""};
    std::ostringstream o;
    REQUIRE(execute(i, o) == 0);
}
