// Exchanging cards
// Problem definition: https://uva.onlinejudge.org/external/116/11678.pdf
// Accepted 2019-06-14

#define CATCH_CONFIG_RUNNER
#include "../catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>

enum class Hand { Alice, Betty, Both };

class Trade
{
public:
    Trade(size_t alice, size_t betty, std::istream& i) {
        std::unordered_map<size_t,Hand> cards;
        size_t uniqueAlice{0};
        size_t uniqueBetty{0};

        size_t c;
        for (size_t j{0}; j < alice; ++j) {
            i >> c;
            if (cards.find(c) == cards.end()) {
                cards[c] = Hand::Alice;
                uniqueAlice++;
            }
        }

        for (size_t j{0}; j < betty; ++j) {
            i >> c;
            if (cards.find(c) == cards.end()) {
                cards[c] = Hand::Betty;
                uniqueBetty++;
            } else if (cards[c] == Hand::Alice) {
                cards[c] = Hand::Both;
                if (uniqueAlice > 0) { uniqueAlice--; }
            }
        }

        m_uniqueAlice = uniqueAlice;
        m_uniqueBetty = uniqueBetty;
        m_min = std::min(uniqueAlice, uniqueBetty);
    }

    const size_t min() const { return m_min; }
    const size_t alice() const { return m_uniqueAlice; }
    const size_t betty() const { return m_uniqueBetty; }

private:
    size_t m_uniqueAlice;
    size_t m_uniqueBetty;
    size_t m_min;
};

int execute(std::istream& in, std::ostream& out) {
    size_t alice, betty;
    while (in >> alice >> betty && alice != 0 && betty != 0) {
        Trade t(alice, betty, in);
        out << t.min() << "\n";
    }
    return 0;
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    //return Catch::Session().run(argc, argv);
    return execute(std::cin, std::cout);
}

TEST_CASE("Size", "[Exchanging cards]") {
    SECTION("No repeats") {
        std::istringstream i{"1\n1 2 3 4 5 10 100 1000 10000 100000\n"};
        Trade t{1, 10, i};
        REQUIRE(t.alice() == 0);
        REQUIRE(t.betty() == 9);
        REQUIRE(t.min() == 0);
    }
    SECTION("Alice repeats") {
        std::istringstream i{"1 1 1 1 1 1 2 3\n1 2 3 4 5 10 100 1000 10000 100000\n"};
        Trade t{8, 10, i};
        REQUIRE(t.alice() == 0);
        REQUIRE(t.betty() == 7);
        REQUIRE(t.min() == 0);
    }
    SECTION("Betty repeats") {
        std::istringstream i{"1 2 3\n1 1 2 2 3 3 4 4 5 5 10 10 100 100 1000 1000 10000 10000 100000 100000\n"};
        Trade t{3, 20, i};
        REQUIRE(t.alice() == 0);
        REQUIRE(t.betty() == 7);
        REQUIRE(t.min() == 0);
    }
    SECTION("Alice has more") {
        std::istringstream i{"1 2 3 4 5 6\n3 4 5 6 7\n"};
        Trade t{6, 5, i};
        REQUIRE(t.alice() == 2);
        REQUIRE(t.betty() == 1);
        REQUIRE(t.min() == 1);
    }
}

TEST_CASE("Execute unit tests", "[Exchanging cards]") {
    std::istringstream i{"1 1\n"
        "1000\n"
        "1000\n"
        "3 4\n"
        "1 3 5\n"
        "2 4 6 8\n"
        "10 9\n"
        "1 1 2 3 5 7 8 8 9 15\n"
        "2 2 2 3 4 6 10 11 11\n"
        "0 0\n"};
    std::ostringstream o;
    REQUIRE(execute(i, o) == 0);
    REQUIRE(o.str() == "0\n3\n4\n");
}
