// Problem definition: https://uva.onlinejudge.org/external/106/10646.pdf
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../catch/catch.hpp"

#include <array>
#include <iostream>
#include <tuple>

using card = std::pair<char,char>;

class Deck
{
public:
    void fill(std::istream& i) {
        std::for_each(m_deck.rbegin(), m_deck.rend(),
            [&i](card& c){ i >> c.first; i >> c.second; });
    }

    const card operator[](const int i) { return m_deck[i]; }

private:
    static constexpr int m_deckSize{52};
    std::array<card,m_deckSize> m_deck;
};


int execute(std::istream& in, std::ostream& out) {
    Deck deck;
    return 0;
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    return Catch::Session().run(argc, argv);
    //return execute(std::cin, std::cout);
}

TEST_CASE("Execute unit tests", "[What is the Card?]"){
    REQUIRE(execute(std::cin, std::cout) == 0);

    SECTION("Stream interfaces") {
        std::istringstream i{""};
        std::ostringstream o{""};
        REQUIRE(execute(i, o) == 0);
        REQUIRE(i.str() == "");
        REQUIRE(o.str() == "");
    }
}

TEST_CASE("Fill deck test", "[What is the Card?]") {
    std::istringstream i{"AC KC QC JC TC 9C 8C 7C 6C 5C 4C 3C 2C AD KD QD JD TD 9D 8D 7D 6D 5D 4D 3D 2D AH KH"
        "QH JH TH 9H 8H 7H 6H 5H 4H 3H 2H AS KS QS JS TS 9S 8S 7S 6S 5S 4S 3S 2S"};
    Deck d;
    d.fill(i);

    REQUIRE(d[0].first == '2');
    REQUIRE(d[0].second == 'S');
    REQUIRE(d[51].first == 'A');
    REQUIRE(d[51].second == 'C');
}