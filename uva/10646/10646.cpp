// Problem definition: https://uva.onlinejudge.org/external/106/10646.pdf
// Accepted 2019-06-08

#define CATCH_CONFIG_RUNNER
#include "../catch/catch.hpp"

#include <algorithm>
#include <array>
#include <iostream>
#include <tuple>

using card = std::pair<char,char>;

std::ostream& operator<<(std::ostream& o, const card& c)
{
    return o << c.first << c.second;
}

class Deck
{
public:
    void fill(std::istream& i) {
        std::for_each(m_deck.rbegin(), m_deck.rend(),
            [&i](card& c){ i >> c.first; i >> c.second; });
    }

    const int value(const card& c) const {
        return (c.first >= '2' && c.first <= '9') ? c.first - '0' : 10;
    }

    const int yIndex() {
        int y{0};
        int index{25};
        for (int i = 0; i < 3; ++i) {
            const card& c{m_deck[index]};
            auto v{value(c)};
            y += v;
            index += 10 - v + 1;
        }

        std::copy_n(m_deck.rbegin() + 27, 25, m_deck.rbegin() + (52 - index));

        return y;
    }

    constexpr int size() const { return m_deckSize; }
    const card operator[](const int i) { return m_deck[i]; }

private:
    static constexpr int m_deckSize{52};
    std::array<card,m_deckSize> m_deck;
};

int execute(std::istream& in, std::ostream& out) {
    int count{0};
    in >> count;

    Deck deck;
    for (int i{1}; i <= count; ++i) {
        deck.fill(in);
        out << "Case " << i << ": " << deck[deck.size() - deck.yIndex()] << "\n";
    }

    return 0;
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    //return Catch::Session().run(argc, argv);
    return execute(std::cin, std::cout);
}

TEST_CASE("Execute unit tests", "[What is the Card?]"){
    std::istringstream i{"2\n"
        "AC KC QC JC TC 9C 8C 7C 6C 5C 4C 3C 2C AD KD QD JD TD 9D 8D 7D 6D 5D 4D 3D 2D AH KH QH JH TH 9H 8H 7H 6H "
        "5H 4H 3H 2H AS KS QS JS TS 9S 8S 7S 6S 5S 4S 3S 2S"
        "AC KC QC JC TC 9C 8C 7C 6C 5C 4C 3C 2C AD KD QD JD TD 9D 8D 7D 6D 5D 4D 3D 2D AH KH QH JH TH 9H 8H 7H 6H "
        "5H 4H 3H 2H AS KS QS JS TS 9S 8S 7S 6S 5S 4S 3S 2S"};
    std::ostringstream o;
    REQUIRE(execute(i, o) == 0);
    REQUIRE(o.str() == "Case 1: 8H\nCase 2: 8H\n");
}

TEST_CASE("Fill deck test", "[What is the Card?]") {
    std::istringstream i{"AC KC QC JC TC 9C 8C 7C 6C 5C 4C 3C 2C AD KD QD JD TD 9D 8D 7D 6D 5D 4D 3D 2D AH KH "
        "QH JH TH 9H 8H 7H 6H 5H 4H 3H 2H AS KS QS JS TS 9S 8S 7S 6S 5S 4S 3S 2S"};
    Deck d;
    d.fill(i);

    REQUIRE(d[0].first == '2');
    REQUIRE(d[0].second == 'S');
    REQUIRE(d[51].first == 'A');
    REQUIRE(d[51].second == 'C');
}

TEST_CASE("Card value", "[What is the Card?]") {
    std::istringstream i{"AC KC QC JC TC 9C 8C 7C 6C 5C 4C 3C 2C AD KD QD JD TD 9D 8D 7D 6D 5D 4D 3D 2D AH KH "
        "QH JH TH 9H 8H 7H 6H 5H 4H 3H 2H AS KS QS JS TS 9S 8S 7S 6S 5S 4S 3S 2S"};
    Deck d;
    d.fill(i);

    REQUIRE(d.value(d[0]) == 2);
    REQUIRE(d.value(d[1]) == 3);
    REQUIRE(d.value(d[2]) == 4);
    REQUIRE(d.value(d[3]) == 5);
    REQUIRE(d.value(d[4]) == 6);
    REQUIRE(d.value(d[5]) == 7);
    REQUIRE(d.value(d[6]) == 8);
    REQUIRE(d.value(d[7]) == 9);
    REQUIRE(d.value(d[47]) == 10);
    REQUIRE(d.value(d[48]) == 10);
    REQUIRE(d.value(d[49]) == 10);
    REQUIRE(d.value(d[50]) == 10);
    REQUIRE(d.value(d[51]) == 10);
}

TEST_CASE("Y index", "[What is the Card?]") {
    Deck d;
    std::istringstream i1{"AC KC QC JC TC 9C 8C 7C 6C 5C 4C 3C 2C AD KD QD JD TD 9D 8D 7D 6D 5D 4D 3D 2D AH KH "
        "QH JH TH 9H 8H 7H 6H 5H 4H 3H 2H AS KS QS JS TS 9S 8S 7S 6S 5S 4S 3S 2S"};
    d.fill(i1);

    auto y1{d.yIndex()};
    REQUIRE(y1 == 22);
    auto c1{d.size() - y1};
    REQUIRE(d[c1].first == '8');
    REQUIRE(d[c1].second == 'H');

    std::istringstream i2{"9C 8C 7C 6C 5C 4C 3C 2C AC KC QC JC TC 9D 8D 7D 6D 5D 4D 3D 2D AD KD QD JD TD 9H 8H "
        "7H 6H 5H 4H 3H 2H AH KH QH JH TH 9S 8S 7S 6S 5S 4S 3S 2S AS KS QS JS TS"};
    d.fill(i2);
    auto y2{d.yIndex()};
    REQUIRE(y2 == 29);
    auto c2{d.size() - y2};
    REQUIRE(d[c2].first == '3');
    REQUIRE(d[c2].second == 'H');
}