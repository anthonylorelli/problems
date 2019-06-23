// Jollo
// Problem definition: https://uva.onlinejudge.org/external/122/12247.pdf
// Accepted 2019-06-23

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
        // Start with one guaranteed win
        if (m_son[1] > m_sister[2]) {
            if (m_son[0] > m_sister[2]) {
                // If we have another guaranteed win then choose lowest card available
                return next(1);
            } else if (m_son[0] > m_sister[1]) {
                // Second son card has two guaranteed wins, so choose another card
                // with two guaranteed wins
                return next(m_sister[1]);
            } else {
                // Second son card can lose against two cards, so we need another
                // cards with three guaranteed wins
                return next(m_sister[2]);
            }
        } else if (m_son[1] > m_sister[1] && m_son[0] > m_sister[1]) {
            // Both cards are guaranteed to win against two sister cards,
            // so we need a third card guaranteed a win against two sister cards
            return next(m_sister[1]);
        } else {
            return noAnswer;
        }
    }

    static constexpr int noAnswer{-1};

    const int next(const int n) const {
        int next{n};
        while (m_cards.find(next) != m_cards.end()) { ++next; }
        return (next > 52) ? noAnswer : next;
    }

    const bool done() const { return m_sister[0] == 0; }

private:
    std::array<int,3> m_sister;
    std::array<int,2> m_son;
    std::set<int> m_cards;
};

int execute(std::istream& in, std::ostream& out) {
    while (true) {
        JolloGame g{in};
        if (g.done()) { break; }
        out << g.card() << "\n";
    }

    return 0;
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    //return Catch::Session().run(argc, argv);
    return execute(std::cin, std::cout);
}

TEST_CASE("Card tests", "[Jollo]") {
    SECTION("Both greater than") {
        // Both cards always win
        std::istringstream i{"1 2 3 4 5"};
        JolloGame g{i};
        REQUIRE(g.card() == 6);
    }
    SECTION("Both less than") {
        // Both cards always lose
        std::istringstream i{"4 5 3 1 2"};
        JolloGame g{i};
        REQUIRE(g.card() == JolloGame::noAnswer);
    }
    SECTION("First sample input") {
        // First card always wins, second can lose
        std::istringstream i{"28 51 29 50 52"};
        JolloGame g{i};
        REQUIRE(g.card() == 30);
    }
    SECTION("Second sample input") {
        // First son card can beat second sister card
        std::istringstream i{"50 26 19 10 27"};
        JolloGame g{i};
        REQUIRE(g.card() == JolloGame::noAnswer);
    }
    SECTION("Third sample input") {
        // Highest card can lose in worst case, second card can win
        std::istringstream i{"10 20 30 24 26"};
        JolloGame g{i};
        REQUIRE(g.card() == 21);
    }
    SECTION("Fourth sample input") {
        // Highest card always wins, second card can lose in worst case
        std::istringstream i{"46 48 49 47 50"};
        JolloGame g{i};
        REQUIRE(g.card() == 51);
    }
    SECTION("Out of bounds sample input") {
        // Highest card always wins, second card can lose in worst case
        // but because of ordering there is no other card we can pick
        // that wins in worst case
        std::istringstream i{"48 50 51 49 52"};
        JolloGame g{i};
        REQUIRE(g.card() == JolloGame::noAnswer);
    }
    SECTION("Always wins, choose smallest card") {
        std::istringstream i{"2 3 4 5 6"};
        JolloGame g{i};
        REQUIRE(g.card() == 1);
    }
    SECTION("Contiguous example") {
        std::istringstream i{"26 27 30 28 31"};
        JolloGame g{i};
        REQUIRE(g.card() == 29);
    }
    SECTION("Spread case") {
        std::istringstream i{"20 30 40 21 50"};
        JolloGame g{i};
        REQUIRE(g.card() == 41);
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
        REQUIRE(g.next(7) == 8);
        REQUIRE(g.next(8) == 8);
    }
    SECTION("Out of bounds") {
        std::istringstream i{"48 49 50 51 52"};
        JolloGame g{i};
        REQUIRE(g.next(52) == JolloGame::noAnswer);
    }
}

TEST_CASE("Execute unit tests", "[Jollo]") {
    std::istringstream i{"28 51 29 50 52\n"
        "50 26 19 10 27\n"
        "10 20 30 24 26\n"
        "46 48 49 47 50\n"
        "0 0 0 0 0"};
    std::ostringstream o;
    REQUIRE(execute(i, o) == 0);
    REQUIRE(o.str() == "30\n-1\n21\n51\n");
}
