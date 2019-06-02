// Problem definition: https://uva.onlinejudge.org/external/103/10315.pdf
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../catch/catch.hpp"

#include <array>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <unordered_map>
#include <memory>

std::unordered_map<char,int> rankToValue{
    {'2',2}, {'3',3}, {'4',4},{'5',5}, {'6',6}, {'7',7}, {'8',8}, 
    {'9',9}, {'T',10},{'J',11}, {'Q',12}, {'K',13}, {'A', 14}
};

std::unordered_map<int,char> valueToRank{
    {2,'2'}, {3,'3'}, {4,'4'},{5,'5'}, {6,'6'}, {7,'7'}, {8,'8'}, 
    {9,'9'}, {10,'T'}, {11,'J'}, {12,'Q'}, {13,'K'}, {14,'A'}
};

constexpr size_t handSize{5};
using card = std::pair<int,char>;
using card_list = std::initializer_list<std::initializer_list<char>>;

class HighCard;
class Pair;
class TwoPairs;
class ThreeOfAKind;
class Straight;
class Flush;
class FullHouse;
class FourOfAKind;
class StraightFlush;

class PokerHand
{
public:
    PokerHand(const card_list& hand)
    {
        std::transform(hand.begin(), hand.end(), cards.begin(), 
            [](const std::initializer_list<char>& c) { return std::make_pair(rankToValue[*c.begin()], *(c.begin()+1)); });
    }
    PokerHand(const std::array<card,handSize>& hand) : cards{hand} {}
    std::array<card,handSize> cards;
    virtual const bool Compare(const PokerHand& hand) const = 0;
    virtual const bool operator>(const HighCard& hc) const  = 0;
    virtual const bool operator>(const Pair& p) const = 0;
    virtual const bool operator>(const TwoPairs& tp) const = 0;
    virtual const bool operator>(const ThreeOfAKind& toak) const = 0;
    virtual const bool operator>(const Straight& s) const = 0;
    virtual const bool operator>(const Flush& f) const = 0;
    virtual const bool operator>(const FullHouse& fh) const = 0;
    virtual const bool operator>(const FourOfAKind& foak) const = 0;
    virtual const bool operator>(const StraightFlush& sf) const = 0;
    const bool ReverseCompare(const PokerHand& hand) const
    {
        auto result{std::mismatch(cards.rbegin(), cards.rend(), hand.cards.rbegin(),
            [](const card& c1, const card& c2) { return c1.first == c2.first; })};

        return !(result.first == cards.rend() || result.first->first <= result.second->first);
    }
};

class HighCard : public PokerHand
{
public:
    HighCard(const card_list& hand) : PokerHand{hand} {}
    HighCard(const std::array<card,handSize>& hand) : PokerHand{hand} {}
    const bool Compare(const PokerHand& hand) const override { return hand > *this; }
    const bool operator>(const HighCard& hc) const override { return ReverseCompare(hc); }
    const bool operator>(const Pair& p) const override { return false; }
    const bool operator>(const TwoPairs& tp) const override { return false; }
    const bool operator>(const ThreeOfAKind& toak) const override { return false; }
    const bool operator>(const Straight& s) const override { return false; }
    const bool operator>(const Flush& f) const override { return false; }
    const bool operator>(const FullHouse& fh) const override { return false; }
    const bool operator>(const FourOfAKind& foak) const override { return false; }
    const bool operator>(const StraightFlush& sf) const override { return false; }
};

class Pair : public PokerHand
{
public:
    Pair(const card_list& hand, const int i) : PokerHand{hand}, m_i{i} {}
    Pair(const std::array<card,handSize>& hand, const int i) : PokerHand{hand}, m_i{i} {}
    const bool Compare(const PokerHand& hand) const override { return hand > *this; }
    const bool operator>(const HighCard& hc) const override { return true; }
    const bool operator>(const Pair& p) const override
    {
        bool result{false};

        if (cards[m_i].first != p.cards[p.m_i].first)
        {
            result = cards[m_i].first > p.cards[p.m_i].first;
        }
        else
        {
            for (auto i{4}; i >= 0; --i)
            {
                if (i == m_i || i == (m_i+1)) { continue; }
                if (cards[i].first != p.cards[i].first)
                {
                    result = cards[i].first > p.cards[i].first;
                    break;
                }
            }
        }
        return result;
    }
    const bool operator>(const TwoPairs& tp) const override { return false; }
    const bool operator>(const ThreeOfAKind& toak) const override { return false; }
    const bool operator>(const Straight& s) const override { return false; }
    const bool operator>(const Flush& f) const override { return false; }
    const bool operator>(const FullHouse& fh) const override { return false; }
    const bool operator>(const FourOfAKind& foak) const override { return false; }
    const bool operator>(const StraightFlush& sf) const override { return false; }

private:
    int m_i;
};

class TwoPairs : public PokerHand
{
public:
    TwoPairs(const card_list& hand, const int i, const int j) : PokerHand{hand}, m_i{i}, m_j{j} 
    {
        m_k = FindSingle();
    }
    TwoPairs(const std::array<card,handSize>& hand, const int i, const int j) : PokerHand{hand}, m_i{i}, m_j{j} 
    {
        m_k = FindSingle();
    }
    const int FindSingle() { return (m_i == 1) ? 0 : (m_j == 2) ? 4 : 3; }
    const bool Compare(const PokerHand& hand) const override { return hand > *this; }
    const bool operator>(const HighCard& hc) const override { return true; }
    const bool operator>(const Pair& p) const override { return true; }
    const bool operator>(const TwoPairs& tp) const override 
    { 
        return (cards[m_i].first == tp.cards[tp.m_i].first) ?
            ((cards[m_j].first == tp.cards[tp.m_j].first) ? (cards[m_k].first > tp.cards[m_k].first) :
                (cards[m_j].first > tp.cards[m_j].first)) :
            (cards[m_i].first > tp.cards[tp.m_i].first);
    }
    const bool operator>(const ThreeOfAKind& toak) const override { return false; }
    const bool operator>(const Straight& s) const override { return false; }
    const bool operator>(const Flush& f) const override { return false; }
    const bool operator>(const FullHouse& fh) const override { return false; }
    const bool operator>(const FourOfAKind& foak) const override { return false; }
    const bool operator>(const StraightFlush& sf) const override { return false; }

private:
    int m_i;
    int m_j;
    int m_k;
};

class ThreeOfAKind : public PokerHand
{
public:
    ThreeOfAKind(const card_list& hand, const int i) : PokerHand{hand}, m_i{i} {}
    ThreeOfAKind(const std::array<card,handSize>& hand, const int i) : PokerHand{hand}, m_i{i} {}
    const bool Compare(const PokerHand& hand) const override { return hand > *this; }
    const bool operator>(const HighCard& hc) const override { return true; }
    const bool operator>(const Pair& p) const override { return true; }
    const bool operator>(const TwoPairs& tp) const override { return true; }
    const bool operator>(const ThreeOfAKind& toak) const override { return cards[m_i].first > toak.cards[toak.m_i].first; }
    const bool operator>(const Straight& s) const override { return false; }
    const bool operator>(const Flush& f) const override { return false; }
    const bool operator>(const FullHouse& fh) const override { return false; }
    const bool operator>(const FourOfAKind& foak) const override { return false; }
    const bool operator>(const StraightFlush& sf) const override { return false; }

private:
    int m_i;
};

class Straight : public PokerHand
{
public:
    Straight(const card_list& hand) : PokerHand{hand} {}
    Straight(const std::array<card,handSize>& hand) : PokerHand{hand} {}
    const bool Compare(const PokerHand& hand) const override { return hand > *this; }
    const bool operator>(const HighCard& hc) const override { return true; }
    const bool operator>(const Pair& p) const override { return true; }
    const bool operator>(const TwoPairs& tp) const override { return true; }
    const bool operator>(const ThreeOfAKind& toak) const override { return true; }
    const bool operator>(const Straight& s) const override { return cards.rbegin()->first > s.cards.rbegin()->first; }
    const bool operator>(const Flush& f) const override { return false; }
    const bool operator>(const FullHouse& fh) const override { return false; }
    const bool operator>(const FourOfAKind& foak) const override { return false; }
    const bool operator>(const StraightFlush& sf) const override { return false; }
};

class Flush : public PokerHand
{
public:
    Flush(const card_list& hand) : PokerHand{hand} {}
    Flush(const std::array<card,handSize>& hand) : PokerHand{hand} {}
    const bool Compare(const PokerHand& hand) const override { return hand > *this; }
    const bool operator>(const HighCard& hc) const override { return true; }
    const bool operator>(const Pair& p) const override { return true; }
    const bool operator>(const TwoPairs& tp) const override { return true; }
    const bool operator>(const ThreeOfAKind& toak) const override { return true; }
    const bool operator>(const Straight& s) const override { return true; }
    const bool operator>(const Flush& f) const override { return ReverseCompare(f); }
    const bool operator>(const FullHouse& fh) const override { return false; }
    const bool operator>(const FourOfAKind& foak) const override { return false; }
    const bool operator>(const StraightFlush& sf) const override { return false; }
};

class FullHouse : public PokerHand
{
public:
    FullHouse(const card_list& hand, const int three, const int pair) : PokerHand{hand}, m_three{three}, m_pair{pair} {}
    FullHouse(const std::array<card,handSize>& hand, const int three, const int pair) :
        PokerHand{hand}, m_three{three}, m_pair{pair} {}
    const bool Compare(const PokerHand& hand) const override { return hand > *this; }
    const bool operator>(const HighCard& hc) const override { return true; }
    const bool operator>(const Pair& p) const override { return true; }
    const bool operator>(const TwoPairs& tp) const override { return true; }
    const bool operator>(const ThreeOfAKind& toak) const override { return true; }
    const bool operator>(const Straight& s) const override { return true; }
    const bool operator>(const Flush& f) const override { return true; }
    const bool operator>(const FullHouse& fh) const override { return cards[m_three].first > fh.cards[fh.m_three].first; }
    const bool operator>(const FourOfAKind& foak) const override { return false; }
    const bool operator>(const StraightFlush& sf) const override { return false; }

private:
    int m_three;
    int m_pair;
};

class FourOfAKind : public PokerHand
{
public:
    FourOfAKind(const card_list& hand, const int four) : PokerHand{hand}, m_four{four} {}
    FourOfAKind(const std::array<card,handSize>& hand, const int four) : PokerHand{hand}, m_four{four} {}
    const bool Compare(const PokerHand& hand) const override { return hand > *this; }
    const bool operator>(const HighCard& hc) const override { return true; }
    const bool operator>(const Pair& p) const override { return true; }
    const bool operator>(const TwoPairs& tp) const override { return true; }
    const bool operator>(const ThreeOfAKind& toak) const override { return true; }
    const bool operator>(const Straight& s) const override { return true; }
    const bool operator>(const Flush& f) const override { return true; }
    const bool operator>(const FullHouse& fh) const override { return true; }
    const bool operator>(const FourOfAKind& foak) const override { return cards[m_four].first > foak.cards[foak.m_four].first; }
    const bool operator>(const StraightFlush& sf) const override { return false; }

private:
    int m_four;
};

class StraightFlush : public PokerHand
{
public:
    StraightFlush(const card_list& hand) : PokerHand{hand} {}
    StraightFlush(const std::array<card,handSize>& hand) : PokerHand{hand} {}
    const bool Compare(const PokerHand& hand) const override { return hand > *this; }
    const bool operator>(const HighCard& hc) const override { return true; }
    const bool operator>(const Pair& p) const override { return true; }
    const bool operator>(const TwoPairs& tp) const override { return true; }
    const bool operator>(const ThreeOfAKind& toak) const override { return true; }
    const bool operator>(const Straight& s) const override { return true; }
    const bool operator>(const Flush& f) const override { return true; }
    const bool operator>(const FullHouse& fh) const override { return true; }
    const bool operator>(const FourOfAKind& foak) const override { return true; }
    const bool operator>(const StraightFlush& sf) const override { return cards.rbegin()->first > sf.cards.rbegin()->first; }
};

const bool operator>(const PokerHand& p1, const PokerHand& p2)
{
    return p2.Compare(p1);
}

//const bool operator==(const PokerHand& p1, const PokerHand& p2)
//{
//    return std::equal(p1.cards.begin(), p1.cards.end(),
//        p2.cards.begin(), p2.cards.end(), 
//        [](const card& c1, const card& c2) { return c1.first == c2.first && c1.second == c2.second; });
//}

std::ostream& operator<<(std::ostream& o, std::array<card,handSize> hand)
{
    o << "Hand: ";
    std::for_each(hand.begin(), hand.end(), [&o](card& c) { o << " " << valueToRank[c.first] << c.second; });
    o << "\n";
    return o;
}

const int IsNOfAKind(const std::array<card,handSize>& hand, const int n)
{
    int result{-1};
    int index{0};
    int count{1};
    int rank{hand[0].first};
    std::for_each(hand.begin()+1, hand.end(), [&](const std::pair<int,char>& c) 
        { 
            index++; 
            if (c.first == rank) { count++; if (count == n) { result = index - n + 1; }} else { rank = c.first; count = 1; }
        });

    return result;
}

std::unique_ptr<PokerHand> MakeHand(std::array<card,handSize>& hand)
{
    // straight flush
    int rank{hand[0].first + 1};
    const char suit{hand[0].second};
    if (std::all_of(hand.begin()+1, hand.end(),
        [&rank, &suit](const card& c) { return c.first == rank++ && c.second == suit; }))
    {
        return std::unique_ptr<StraightFlush>(new StraightFlush(hand));
    }

    // four of a kind
    int n{4};
    int i{IsNOfAKind(hand, n)};
    if (i >= 0)
    {
        return std::unique_ptr<FourOfAKind>(new FourOfAKind(hand, i));
    }

    // full house
    if (hand[0].first == hand[1].first && hand[1].first == hand[2].first && hand[3].first == hand[4].first)
    {
        return std::unique_ptr<FullHouse>(new FullHouse(hand, 0, 3));
    }
    else if (hand[0].first == hand[1].first && hand[2].first == hand[3].first && hand[3].first == hand[4].first)
    {
        return std::unique_ptr<FullHouse>(new FullHouse(hand, 2, 0));
    }

    // flush
    if (std::all_of(hand.begin()+1, hand.end(), 
        [&suit](const card& c) { return c.second == suit; }))
    {
        return std::unique_ptr<Flush>(new Flush(hand));
    }

    // straight
    rank = hand[0].first + 1;
    if (std::all_of(hand.begin()+1, hand.end(), 
        [&rank](const card& c) { return c.first == rank++; }))
    {
        return std::unique_ptr<Straight>(new Straight(hand));
    }

    // three of a kind
    i = IsNOfAKind(hand, 3);
    if (i >= 0)
    {
        return std::unique_ptr<ThreeOfAKind>(new ThreeOfAKind(hand, i));
    }

    // two pairs
    auto findPair{[](const card& c1, const card& c2) { return c1.first == c2.first; }};
    auto first{std::adjacent_find(hand.begin(), hand.end(), findPair)};
    auto second{(first != hand.end() && first + 2 != hand.end()) ?
        std::adjacent_find(first+2, hand.end(), findPair) : hand.end()};
    if (second != hand.end())
    {
        auto i{first - hand.begin()};
        auto j{second - hand.begin()};
        return std::unique_ptr<TwoPairs>(new TwoPairs(hand, i, j));
    }

    // pair
    i = IsNOfAKind(hand, 2);
    if (i >= 0)
    {
        return std::unique_ptr<Pair>(new Pair(hand, i));
    }

    // high card
    return std::unique_ptr<HighCard>(new HighCard(hand));
}

int execute(std::istream& in, std::ostream& out)
{
    std::array<card,handSize> blackCards;
    std::array<card,handSize> whiteCards;

    char rank, suit;
    auto assignCard{[&in, &rank](card& c) 
    { 
        in >> rank >> c.second; 
        c.first = rankToValue[rank];
    }};
    auto sortHand([](const card& c1, const card& c2) { return c1.first < c2.first; });

    while (in >> rank >> suit)
    {
        blackCards[0].first = rankToValue[rank];
        blackCards[0].second = suit;
        std::for_each(blackCards.begin() + 1, blackCards.end(), assignCard);
        std::for_each(whiteCards.begin(), whiteCards.end(), assignCard);
        std::sort(blackCards.begin(), blackCards.end(), sortHand);
        std::sort(whiteCards.begin(), whiteCards.end(), sortHand);
        auto blackHand{MakeHand(blackCards)};
        auto whiteHand{MakeHand(whiteCards)};
        out <<((*blackHand.get() > *whiteHand.get()) ? "Black wins." : 
            (*whiteHand.get() > *blackHand.get()) ? "White wins." : "Tie.") << "\n";
    }

    return 0;
}

int main(int argc, char* argv[])
{
    std::ios_base::sync_with_stdio(false);

    //return Catch::Session().run(argc, argv);
    return execute(std::cin, std::cout);
}

TEST_CASE("Game logic test", "[PokerHand]")
{
    std::string input{"2H 3D 5S 9C KD 2C 3H 4S 8C AH\n"
        "2H 4S 4C 2D 4H 2S 8S AS QS 3S\n"
        "2H 3D 5S 9C KD 2C 3H 4S 8C KH\n"
        "2H 3D 5S 9C KD 2D 3H 5C 9S KH\n"};
    std::string output{"White wins.\n"
        "Black wins.\n"
        "Black wins.\n"
        "Tie.\n"};
    std::istringstream i{input};
    std::ostringstream o;

    REQUIRE(execute(i, o) == 0);
    REQUIRE(o.str() == output);
}

TEST_CASE("Matching hand comparison", "[PokerHands]")
{
    SECTION("Straight flush")
    {
        std::array<card,handSize> sf1{std::make_pair(2,'H'), std::make_pair(3,'H'), 
            std::make_pair(4,'H'), std::make_pair(5, 'H'), std::make_pair(6,'H')};
        std::array<card,handSize> sf2{std::make_pair(3,'C'), std::make_pair(4,'C'), 
            std::make_pair(5,'C'), std::make_pair(6, 'C'), std::make_pair(7,'C')};

        auto sfh1{MakeHand(sf1)};
        auto sfh2{MakeHand(sf2)};

        REQUIRE(*sfh2.get() > *sfh1.get());
        REQUIRE(!(*sfh1.get() > *sfh2.get()));
    }
    SECTION("Four of a kind")
    {
        std::array<card,handSize> foak1{std::make_pair(2,'H'), std::make_pair(2,'D'), 
            std::make_pair(2,'C'), std::make_pair(2, 'S'), std::make_pair(3,'H')};
        std::array<card,handSize> foak2{std::make_pair(4,'H'), std::make_pair(4,'D'), 
            std::make_pair(4,'C'), std::make_pair(4, 'S'), std::make_pair(5,'H')};

        auto foakh1{MakeHand(foak1)};
        auto foakh2{MakeHand(foak2)};

        REQUIRE(!(*foakh1.get() > *foakh2.get()));
        REQUIRE(*foakh2.get() > *foakh1.get());
    }
    SECTION("Full house")
    {
        std::array<card,handSize> fh1{std::make_pair(2,'H'), std::make_pair(2,'D'), 
            std::make_pair(3,'C'), std::make_pair(3, 'S'), std::make_pair(3,'H')};
        std::array<card,handSize> fh2{std::make_pair(4,'H'), std::make_pair(4,'D'), 
            std::make_pair(5,'C'), std::make_pair(5, 'S'), std::make_pair(5,'H')};

        auto fhh1{MakeHand(fh1)};
        auto fhh2{MakeHand(fh2)};

        REQUIRE(!(*fhh1.get() > *fhh2.get()));
        REQUIRE(*fhh2.get() > *fhh1.get());
    }
    SECTION("Flush")
    {
        std::array<card,handSize> f1{std::make_pair(2,'H'), std::make_pair(5,'H'), 
            std::make_pair(6,'H'), std::make_pair(9, 'H'), std::make_pair(11,'H')};
        std::array<card,handSize> f2{std::make_pair(3,'C'), std::make_pair(5,'C'), 
            std::make_pair(6,'C'), std::make_pair(9, 'C'), std::make_pair(11,'C')};
        std::array<card,handSize> f3{std::make_pair(3,'D'), std::make_pair(5,'D'), 
            std::make_pair(6,'D'), std::make_pair(9, 'D'), std::make_pair(11,'D')};

        auto fh1{MakeHand(f1)};
        auto fh2{MakeHand(f2)};
        auto fh3{MakeHand(f3)};

        REQUIRE(!(*fh1.get() > *fh2.get()));
        REQUIRE(*fh2.get() > *fh1.get());
        REQUIRE(!(*fh2.get() > *fh3.get()));
        REQUIRE(!(*fh3.get() > *fh2.get()));
    }
    SECTION("Straight")
    {
        std::array<card,handSize> s1{std::make_pair(2,'H'), std::make_pair(3,'H'), 
            std::make_pair(4,'H'), std::make_pair(5, 'H'), std::make_pair(6,'S')};
        std::array<card,handSize> s2{std::make_pair(3,'C'), std::make_pair(4,'C'), 
            std::make_pair(5,'C'), std::make_pair(6, 'C'), std::make_pair(7,'H')};
        std::array<card,handSize> s3{std::make_pair(3,'C'), std::make_pair(4,'C'), 
            std::make_pair(5,'C'), std::make_pair(6, 'C'), std::make_pair(7,'H')};

        auto sh1{MakeHand(s1)};
        auto sh2{MakeHand(s2)};
        auto sh3{MakeHand(s3)};

        REQUIRE(!(*sh1.get() > *sh2.get()));
        REQUIRE(*sh2.get() > *sh1.get());
        REQUIRE(!(*sh2.get() > *sh3.get()));
        REQUIRE(!(*sh3.get() > *sh2.get()));
    }
    SECTION("Three of a kind")
    {
        std::array<card,handSize> toak1{std::make_pair(2,'H'), std::make_pair(3,'H'), 
            std::make_pair(4,'H'), std::make_pair(4, 'H'), std::make_pair(4,'S')};
        std::array<card,handSize> toak2{std::make_pair(3,'C'), std::make_pair(4,'C'), 
            std::make_pair(5,'C'), std::make_pair(5, 'C'), std::make_pair(5,'H')};
        std::array<card,handSize> toak3{std::make_pair(3,'C'), std::make_pair(4,'C'), 
            std::make_pair(5,'C'), std::make_pair(5, 'C'), std::make_pair(5,'H')};

        auto toakh1{MakeHand(toak1)};
        auto toakh2{MakeHand(toak2)};
        auto toakh3{MakeHand(toak3)};

        REQUIRE(!(*toakh1.get() > *toakh2.get()));
        REQUIRE(*toakh2.get() > *toakh1.get());
        REQUIRE(!(*toakh2.get() > *toakh3.get()));
        REQUIRE(!(*toakh3.get() > *toakh2.get()));
    }
    SECTION("Two pairs")
    {
        std::array<card,handSize> tp1{std::make_pair(2,'H'), std::make_pair(2,'H'), 
            std::make_pair(4,'H'), std::make_pair(4, 'H'), std::make_pair(8,'S')};
        std::array<card,handSize> tp2{std::make_pair(3,'C'), std::make_pair(3,'C'), 
            std::make_pair(5,'C'), std::make_pair(5, 'C'), std::make_pair(8,'H')};
        std::array<card,handSize> tp3{std::make_pair(4,'C'), std::make_pair(4,'C'), 
            std::make_pair(5,'C'), std::make_pair(5, 'C'), std::make_pair(8,'H')};
        std::array<card,handSize> tp4{std::make_pair(4,'C'), std::make_pair(4,'C'), 
            std::make_pair(5,'C'), std::make_pair(5, 'C'), std::make_pair(8,'H')};

        auto tph1{MakeHand(tp1)};
        auto tph2{MakeHand(tp2)};
        auto tph3{MakeHand(tp3)};
        auto tph4{MakeHand(tp4)};

        REQUIRE(!(*tph1.get() > *tph2.get()));
        REQUIRE(*tph2.get() > *tph1.get());
        REQUIRE(!(*tph2.get() > *tph3.get()));
        REQUIRE(*tph3.get() > *tph2.get());
        REQUIRE(!(*tph3.get() > *tph4.get()));
        REQUIRE(!(*tph4.get() > *tph3.get()));
    }
    SECTION("Pair")
    {
        std::array<card,handSize> p1{std::make_pair(2,'H'), std::make_pair(2,'H'), 
            std::make_pair(4,'H'), std::make_pair(5, 'H'), std::make_pair(8,'S')};
        std::array<card,handSize> p2{std::make_pair(3,'C'), std::make_pair(3,'C'), 
            std::make_pair(5,'C'), std::make_pair(6, 'C'), std::make_pair(8,'H')};
        std::array<card,handSize> p3{std::make_pair(4,'C'), std::make_pair(4,'C'), 
            std::make_pair(5,'C'), std::make_pair(6, 'C'), std::make_pair(8,'H')};
        std::array<card,handSize> p4{std::make_pair(4,'C'), std::make_pair(4,'C'), 
            std::make_pair(5,'C'), std::make_pair(7, 'C'), std::make_pair(8,'H')};
        std::array<card,handSize> p5{std::make_pair(4,'C'), std::make_pair(4,'C'), 
            std::make_pair(5,'C'), std::make_pair(7, 'C'), std::make_pair(8,'H')};
        std::array<card,handSize> p6{std::make_pair(4,'C'), std::make_pair(4,'C'), 
            std::make_pair(6,'C'), std::make_pair(7, 'C'), std::make_pair(8,'H')};


        auto ph1{MakeHand(p1)};
        auto ph2{MakeHand(p2)};
        auto ph3{MakeHand(p3)};
        auto ph4{MakeHand(p4)};
        auto ph5{MakeHand(p5)};
        auto ph6{MakeHand(p6)};

        REQUIRE(!(*ph1.get() > *ph2.get()));
        REQUIRE(*ph2.get() > *ph1.get());
        REQUIRE(!(*ph2.get() > *ph3.get()));
        REQUIRE(*ph3.get() > *ph2.get());
        REQUIRE(!(*ph3.get() > *ph4.get()));
        REQUIRE(*ph4.get() > *ph3.get());
        REQUIRE(!(*ph4.get() > *ph5.get()));
        REQUIRE(!(*ph5.get() > *ph4.get()));
        REQUIRE(!(*ph5.get() > *ph6.get()));
        REQUIRE(*ph6.get() > *ph5.get());
    }
    SECTION("High card")
    {
        std::array<card,handSize> hc1{std::make_pair(2,'H'), std::make_pair(4,'H'), 
            std::make_pair(5,'H'), std::make_pair(7, 'H'), std::make_pair(8,'S')};
        std::array<card,handSize> hc2{std::make_pair(3,'C'), std::make_pair(4,'C'), 
            std::make_pair(5,'C'), std::make_pair(7, 'C'), std::make_pair(8,'H')};
        std::array<card,handSize> hc3{std::make_pair(4,'C'), std::make_pair(4,'C'), 
            std::make_pair(5,'C'), std::make_pair(6, 'C'), std::make_pair(9,'H')};
        std::array<card,handSize> hc4{std::make_pair(4,'C'), std::make_pair(4,'C'), 
            std::make_pair(5,'C'), std::make_pair(6, 'C'), std::make_pair(9,'H')};

        auto hch1{MakeHand(hc1)};
        auto hch2{MakeHand(hc2)};
        auto hch3{MakeHand(hc3)};
        auto hch4{MakeHand(hc4)};

        REQUIRE(!(*hch1.get() > *hch2.get()));
        REQUIRE(*hch2.get() > *hch1.get());
        REQUIRE(!(*hch2.get() > *hch3.get()));
        REQUIRE(*hch3.get() > *hch2.get());
        REQUIRE(!(*hch3.get() > *hch3.get()));
        REQUIRE(!(*hch4.get() > *hch3.get()));
    }
}

TEST_CASE("Hand recognition", "[PokerHands]")
{
    std::array<card,handSize> sf{std::make_pair(2,'H'), std::make_pair(3,'H'), 
        std::make_pair(4,'H'), std::make_pair(5, 'H'), std::make_pair(6,'H')};
    std::array<card,handSize> foak{std::make_pair(2,'H'), std::make_pair(2,'D'), 
        std::make_pair(2,'C'), std::make_pair(2, 'S'), std::make_pair(3,'H')};
    std::array<card,handSize> fh{std::make_pair(2,'H'), std::make_pair(2,'D'), 
        std::make_pair(3,'C'), std::make_pair(3, 'S'), std::make_pair(3,'H')};
    std::array<card,handSize> f{std::make_pair(2,'H'), std::make_pair(5,'H'), 
        std::make_pair(6,'H'), std::make_pair(9, 'H'), std::make_pair(11,'H')};
    std::array<card,handSize> s{std::make_pair(2,'H'), std::make_pair(3,'D'), 
        std::make_pair(4,'C'), std::make_pair(5, 'S'), std::make_pair(6,'H')};
    std::array<card,handSize> toak{std::make_pair(2,'H'), std::make_pair(2,'D'), 
        std::make_pair(2,'C'), std::make_pair(3, 'S'), std::make_pair(8,'H')};
    std::array<card,handSize> tp{std::make_pair(2,'H'), std::make_pair(2,'D'), 
        std::make_pair(8,'C'), std::make_pair(8, 'S'), std::make_pair(10,'H')};
    std::array<card,handSize> p{std::make_pair(2,'H'), std::make_pair(7,'D'), 
        std::make_pair(8,'C'), std::make_pair(10, 'S'), std::make_pair(10,'H')};
    std::array<card,handSize> hc{std::make_pair(5,'H'), std::make_pair(7,'D'), 
        std::make_pair(8,'C'), std::make_pair(11, 'S'), std::make_pair(13,'H')};

    REQUIRE(sf.size() == handSize);

    auto sf1{MakeHand(sf)};
    auto foak1{MakeHand(foak)};
    auto fh1{MakeHand(fh)};
    auto f1{MakeHand(f)};
    auto s1{MakeHand(s)};
    auto toak1{MakeHand(toak)};
    auto tp1{MakeHand(tp)};
    auto p1{MakeHand(p)};
    auto hc1{MakeHand(hc)};

    SECTION("Straight flush")
    {
        REQUIRE(foak1->Compare(*sf1.get()));
        REQUIRE(*sf1.get() > *foak1.get());
        REQUIRE(!(*foak1.get() > *sf1.get()));
        REQUIRE(*sf1.get() > *fh1.get());
        REQUIRE(*sf1.get() > *f1.get());
        REQUIRE(*sf1.get() > *s1.get());
        REQUIRE(*sf1.get() > *toak1.get());
        REQUIRE(*sf1.get() > *tp1.get());
        REQUIRE(*sf1.get() > *p1.get());
        REQUIRE(*sf1.get() > *hc1.get());
    }
    SECTION("Four of a kind")
    {
        REQUIRE(!(sf1->Compare(*foak1.get())));
        REQUIRE(!(*foak1.get() > *foak1.get()));
        REQUIRE(fh1->Compare(*foak1.get()));
        REQUIRE(f1->Compare(*foak1.get()));
        REQUIRE(*f1.get() > *s1.get());
        REQUIRE(*f1.get() > *toak1.get());
        REQUIRE(*f1.get() > *tp1.get());
        REQUIRE(*f1.get() > *p1.get());
        REQUIRE(*f1.get() > *hc1.get());
    }
    SECTION("Full house")
    {
        REQUIRE(!(*fh1.get() > *sf1.get()));
        REQUIRE(!(*fh1.get() > *foak1.get()));
        REQUIRE(!(*fh1.get() > *fh1.get()));
        REQUIRE(*fh1.get() > *s1.get());
        REQUIRE(*fh1.get() > *toak1.get());
        REQUIRE(*fh1.get() > *tp1.get());
        REQUIRE(*fh1.get() > *p1.get());
        REQUIRE(*fh1.get() > *hc1.get());
    }
    SECTION("Flush")
    {

    }
    SECTION("Straight")
    {
        REQUIRE(!(*s1.get() > *sf1.get()));
        REQUIRE(!(*s1.get() > *foak1.get()));
        REQUIRE(!(*s1.get() > *fh1.get()));
        REQUIRE(!(*s1.get() > *s1.get()));
        REQUIRE(*s1.get() > *toak1.get());
        REQUIRE(*s1.get() > *tp1.get());
        REQUIRE(*s1.get() > *p1.get());
        REQUIRE(*s1.get() > *hc1.get());
    }
    SECTION("Three of a kind")
    {
        REQUIRE(!(*toak1.get() > *sf1.get()));
        REQUIRE(!(*toak1.get() > *foak1.get()));
        REQUIRE(!(*toak1.get() > *fh1.get()));
        REQUIRE(!(*toak1.get() > *s1.get()));
        REQUIRE(!(*toak1.get() > *toak1.get()));
        REQUIRE(*s1.get() > *tp1.get());
        REQUIRE(*s1.get() > *p1.get());
        REQUIRE(*s1.get() > *hc1.get());
    }
    SECTION("Two pairs")
    {
        REQUIRE(!(*tp1.get() > *sf1.get()));
        REQUIRE(!(*tp1.get() > *foak1.get()));
        REQUIRE(!(*tp1.get() > *fh1.get()));
        REQUIRE(!(*tp1.get() > *s1.get()));
        REQUIRE(!(*tp1.get() > *toak1.get()));
        REQUIRE(!(*tp1.get() > *tp1.get()));
        REQUIRE(*s1.get() > *p1.get());
        REQUIRE(*s1.get() > *hc1.get());
    }
    SECTION("Pair")
    {
        REQUIRE(!(*p1.get() > *sf1.get()));
        REQUIRE(!(*p1.get() > *foak1.get()));
        REQUIRE(!(*p1.get() > *fh1.get()));
        REQUIRE(!(*p1.get() > *s1.get()));
        REQUIRE(!(*p1.get() > *toak1.get()));
        REQUIRE(!(*p1.get() > *tp1.get()));
        REQUIRE(!(*p1.get() > *p1.get()));
        REQUIRE(*s1.get() > *hc1.get());
    }
    SECTION("High card")
    {
        REQUIRE(!(*hc1.get() > *sf1.get()));
        REQUIRE(!(*hc1.get() > *foak1.get()));
        REQUIRE(!(*hc1.get() > *fh1.get()));
        REQUIRE(!(*hc1.get() > *s1.get()));
        REQUIRE(!(*hc1.get() > *toak1.get()));
        REQUIRE(!(*hc1.get() > *tp1.get()));
        REQUIRE(!(*hc1.get() > *p1.get()));
        REQUIRE(!(*hc1.get() > *hc1.get()));
    }
}

TEST_CASE("N of a kind", "[PokerHands]")
{
    std::array<card,handSize> h1{std::make_pair(2,'H'), std::make_pair(2,'D'), 
        std::make_pair(2,'C'), std::make_pair(2, 'S'), std::make_pair(3,'H')};

    SECTION("N == 4")
    {
        REQUIRE(IsNOfAKind(h1, 4) == 0);
    }
    SECTION("N == 3")
    {
        REQUIRE(IsNOfAKind(h1, 3) == 0);
    }
    SECTION("N == 2")
    {
        REQUIRE(IsNOfAKind(h1, 2) == 0);
    }

    std::array<card,handSize> h2{std::make_pair(11,'H'), std::make_pair(2,'D'), 
        std::make_pair(2,'C'), std::make_pair(2, 'S'), std::make_pair(3,'H')};

    SECTION("N == 4")
    {
        REQUIRE(IsNOfAKind(h2, 4) == -1);
    }
    SECTION("N == 3")
    {
        REQUIRE(IsNOfAKind(h2, 3) == 1);
    }
    SECTION("N == 2")
    {
        REQUIRE(IsNOfAKind(h2, 2) == 1);
    }

    std::array<card,handSize> h3{std::make_pair(11,'H'), std::make_pair(3,'D'), 
        std::make_pair(4,'C'), std::make_pair(2, 'S'), std::make_pair(2,'H')};

    SECTION("N == 4")
    {
        REQUIRE(IsNOfAKind(h3, 4) == -1);
    }
    SECTION("N == 3")
    {
        REQUIRE(IsNOfAKind(h3, 3) == -1);
    }
    SECTION("N == 2")
    {
        REQUIRE(IsNOfAKind(h3, 2) == 3);
    }
}

TEST_CASE("Hand greater than comparisons", "[PokerHands]")
{
    StraightFlush sf{{'2','H'},{'3','H'},{'4','H'},{'5','H'},{'6','H'}};
    FourOfAKind foak{{{'2','C'},{'2','D'},{'2','H'},{'2','S'},{'6','H'}}, 0};
    FullHouse fh{{{'2','C'},{'2','D'},{'2','C'},{'5','H'},{'5','S'}}, 0, 3};
    Flush f{{'2','H'},{'6','H'},{'9','H'},{'J','H'},{'K','H'}};
    Straight s{{'2','H'},{'3','S'},{'4','D'},{'5','C'},{'6','C'}};
    ThreeOfAKind toak{{{'2','H'},{'3','H'},{'4','D'},{'4','H'},{'4','S'}}, 2};
    TwoPairs tp{{{'2','H'},{'3','H'},{'3','S'},{'6','H'},{'6','S'}}, 1, 3};
    Pair p{{{'2','H'},{'2','S'},{'4','H'},{'5','H'},{'6','H'}}, 0};
    HighCard hc{{'2','S'},{'5','H'},{'6','D'},{'9','H'},{'J','S'}};

    SECTION("Straight flush")
    {
        StraightFlush sf1{{'3','H'},{'4','H'},{'5','H'},{'6','H'},{'7','H'}};
        StraightFlush sf2{{'2','H'},{'3','H'},{'4','H'},{'5','H'},{'6','H'}};
        StraightFlush sf3{{'2','H'},{'3','H'},{'4','H'},{'5','H'},{'6','H'}};

        REQUIRE(sf1 > sf2);
        REQUIRE(!(sf2 > sf1));
        REQUIRE(!(sf2 > sf3));
        //REQUIRE(sf2 == sf3);
        REQUIRE(sf > foak);
        REQUIRE(sf > fh);
        REQUIRE(sf > f);
        REQUIRE(sf > s);
        REQUIRE(sf > toak);
        REQUIRE(sf > tp);
        REQUIRE(sf > p);
        REQUIRE(sf > hc);
    }
    SECTION("Four of a kind")
    {
        REQUIRE(!(foak > sf));
        REQUIRE(!(foak > foak));
        REQUIRE(foak > fh);
        REQUIRE(foak > f);
        REQUIRE(foak > s);
        REQUIRE(foak > toak);
        REQUIRE(foak > tp);
        REQUIRE(foak > p);
        REQUIRE(foak > hc);
    }
    SECTION("Full house")
    {
        REQUIRE(!(fh > sf));
        REQUIRE(!(fh > foak));
        REQUIRE(!(fh > fh));
        REQUIRE(fh > f);
        REQUIRE(fh > s);
        REQUIRE(fh > toak);
        REQUIRE(fh > tp);
        REQUIRE(fh > p);
        REQUIRE(fh > hc);
    }
    SECTION("Flush")
    {
        REQUIRE(!(f > sf));
        REQUIRE(!(f > foak));
        REQUIRE(!(f > fh));
        REQUIRE(!(f > f));
        REQUIRE(f > s);
        REQUIRE(f > toak);
        REQUIRE(f > tp);
        REQUIRE(f > p);
        REQUIRE(f > hc);
    }
    SECTION("Straight")
    {
        REQUIRE(!(s > sf));
        REQUIRE(!(s > foak));
        REQUIRE(!(s > fh));
        REQUIRE(!(s > f));
        REQUIRE(!(s > s));
        REQUIRE(s > toak);
        REQUIRE(s > tp);
        REQUIRE(s > p);
        REQUIRE(s > hc);
    }
    SECTION("Three of a kind")
    {
        REQUIRE(!(toak > sf));
        REQUIRE(!(toak > foak));
        REQUIRE(!(toak > fh));
        REQUIRE(!(toak > f));
        REQUIRE(!(toak > s));
        REQUIRE(!(toak > toak));
        REQUIRE(toak > tp);
        REQUIRE(toak > p);
        REQUIRE(toak > hc);
    }
    SECTION("Two pairs")
    {
        REQUIRE(!(tp > sf));
        REQUIRE(!(tp > foak));
        REQUIRE(!(tp > fh));
        REQUIRE(!(tp > f));
        REQUIRE(!(tp > s));
        REQUIRE(!(tp > toak));
        REQUIRE(!(tp > tp));
        REQUIRE(tp > p);
        REQUIRE(tp > hc);
    }
    SECTION("Pair")
    {
        REQUIRE(!(p > sf));
        REQUIRE(!(p > foak));
        REQUIRE(!(p > fh));
        REQUIRE(!(p > f));
        REQUIRE(!(p > s));
        REQUIRE(!(p > toak));
        REQUIRE(!(p > tp));
        REQUIRE(!(p > p));
        REQUIRE(p > hc);
    }
    SECTION("High card")
    {
        REQUIRE(!(hc > sf));
        REQUIRE(!(hc > foak));
        REQUIRE(!(hc > fh));
        REQUIRE(!(hc > f));
        REQUIRE(!(hc > s));
        REQUIRE(!(hc > toak));
        REQUIRE(!(hc > tp));
        REQUIRE(!(hc > p));
        REQUIRE(!(hc > hc));
    }
}
