// Problem definition: https://uva.onlinejudge.org/external/103/10315.pdf
// Accepted ?

#include <array>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define CATCH_CONFIG_RUNNER
#include "../catch/catch.hpp"

constexpr size_t handSize{5};
using card = std::pair<int,char>;

class PokerHand
{
public:
    std::array<card,handSize> cards;
};

class HighCard : public PokerHand
{

};

class Pair : public PokerHand
{

};

class TwoPairs : public PokerHand
{

};

class ThreeOfAKind : public PokerHand
{

};

class Straight : public PokerHand
{

};

class Flush : public PokerHand
{

};

class FullHouse : public PokerHand
{

};

class FourOfAKind : public PokerHand
{

};

class StraightFlush : public PokerHand
{

};

std::unordered_map<char,int> rankToValue{
    {'2',2}, {'3',3}, {'4',4},{'5',5}, {'6',6}, {'7',7}, {'8',8}, 
    {'9',9}, {'T',10},{'J',11}, {'Q',12}, {'K',13}, {'A', 14}
};

std::unordered_map<int,char> valueToRank{
    {2,'2'}, {3,'3'}, {4,'4'},{5,'5'}, {6,'6'}, {7,'7'}, {8,'8'}, 
    {9,'9'}, {10,'T'}, {11,'J'}, {12,'Q'}, {13,'K'}, {14,'A'}
};

std::ostream& operator<<(std::ostream& o, std::array<card,handSize> hand)
{
    o << "Hand: ";
    std::for_each(hand.begin(), hand.end(), [&o](card& c) { o << " " << valueToRank[c.first] << c.second; });
    o << "\n";
    return o;
}

enum class HandType
{
    HighCard,
    Pair,
    TwoPairs,
    ThreeOfAKind,
    Straight,
    Flush,
    FullHouse,
    FourOfAKind,
    StraightFlush
};

bool IsNOfAKind(const std::array<card,handSize>& hand, const int n)
{
    bool result{false};
    int count{1};
    int rank{hand[0].first};
    std::for_each(hand.begin()+1, hand.end(), [&](const std::pair<int,char>& c) 
        { if (c.first == rank) { count++; if (count == n) { result = true; }} else { rank = c.first; count = 1; }});

    return result;
}

bool IsTwoPairs(const std::array<card,handSize>& hand)
{
    auto findPair{[](const card& c1, const card& c2) { return c1.first == c2.first; }};
    auto first{std::adjacent_find(hand.begin(), hand.end(), findPair)};
    auto second{(first != hand.end() && first + 2 != hand.end()) ?
        std::adjacent_find(first+2, hand.end(), findPair) : hand.end()};
    return second != hand.end();
}

bool IsStraight(const std::array<card,handSize>& hand)
{
    int rank{hand[0].first + 1};
    return std::all_of(hand.begin()+1, hand.end(), 
        [&rank](const card& c) { return c.first == rank++; });
}

bool IsStraightFlush(const std::array<card,handSize>& hand)
{
    int rank{hand[0].first + 1};
    const char suit{hand[0].second};
    return std::all_of(hand.begin()+1, hand.end(),
        [&rank, &suit](const card& c) { return c.first == rank++ && c.second == suit; });
}

card HighCard(const std::array<card,handSize>& hand)
{
    return hand[handSize - 1];
}

bool IsPair(const std::array<card,handSize>& hand)
{
    return IsNOfAKind(hand, 2);
}

bool IsThreeOfAKind(const std::array<card,handSize>& hand)
{
    return IsNOfAKind(hand, 3);
}

bool IsFullHouse(const std::array<card,handSize>& hand)
{
    return (hand[0].first == hand[1].first && hand[1].first == hand[2].first && hand[3].first == hand[4].first) ||
        (hand[0].first == hand[1].first && hand[2].first == hand[3].first && hand[3].first == hand[4].first);
}

bool IsFourOfAKind(const std::array<card,handSize>& hand)
{
    return IsNOfAKind(hand, 4);
}

bool IsFlush(const std::array<card,handSize>& hand)
{
    const char suit{hand[0].second};
    return std::all_of(hand.begin()+1, hand.end(), 
        [&suit](const card& c) { return c.second == suit; });
}

HandType ClassifyHand(const std::array<card,handSize>& hand)
{
    auto type = IsStraightFlush(hand) ? HandType::StraightFlush :
        IsFourOfAKind(hand) ? HandType::FourOfAKind :
        IsFullHouse(hand) ? HandType::FullHouse :
        IsFlush(hand) ? HandType::Flush :
        IsStraight(hand) ? HandType::Straight :
        IsThreeOfAKind(hand) ? HandType::ThreeOfAKind :
        IsTwoPairs(hand) ? HandType::TwoPairs :
        IsPair(hand) ? HandType::Pair : HandType::HighCard;

    return type;
}

bool operator>(const HandType t1, const HandType t2)
{
    if (t1 == HandType::StraightFlush)
    {
        return !(t2 == HandType::StraightFlush);
    }
    else if (t2 == HandType::StraightFlush)
    {
        return false;
    }
    else if (t1 == HandType::FourOfAKind)
    {
        return !(t2 == HandType::FourOfAKind);
    } 
    else if (t2 == HandType::FourOfAKind)
    {
        return false;
    }
    else if (t1 == HandType::FullHouse)
    {
        return !(t2 == HandType::FullHouse);
    }
    else if (t2 == HandType::FullHouse)
    {
        return false;
    }
    else if (t1 == HandType::Flush)
    {
        return !(t2 == HandType::Flush);
    }
    else if (t2 == HandType::Flush)
    {
        return false;
    }
    else if (t1 == HandType::Straight)
    {
        return !(t2 == HandType::Straight);
    }
    else if (t2 == HandType::Straight)
    {
        return false;
    }
    else if (t1 == HandType::ThreeOfAKind)
    {
        return !(t2 == HandType::ThreeOfAKind);
    }
    else if (t2 == HandType::ThreeOfAKind)
    {
        return false;
    }
    else if (t1 == HandType::TwoPairs)
    {
        return !(t2 == HandType::TwoPairs);
    }
    else if (t2 == HandType::TwoPairs)
    {
        return false;
    }
    else if (t1 == HandType::Pair)
    {
        return !(t2 == HandType::Pair);
    }
    else if (t2 == HandType::Pair)
    {
        return false;
    }
    
    return false;
}

enum class Winner
{
    Black,
    White,
    Tie
};

const Winner BreakTie(const HandType type, const std::array<card,handSize>& blackHand, 
    const std::array<card,handSize>& whiteHand)
{
    Winner winner;

    if (type == HandType::Straight || type == HandType::StraightFlush)
    {
        const card blackHighCard{HighCard(blackHand)};
        const card whiteHighCard{HighCard(whiteHand)};
        winner = blackHighCard == whiteHighCard ? Winner::Tie :
            blackHighCard > whiteHighCard ? Winner::Black : Winner::White;
    }

    return winner;
}

const Winner ChooseWinner(const HandType blackType, const std::array<card,handSize>& blackHand, 
    const HandType whiteType, const std::array<card,handSize>& whiteHand)
{
    return (blackType == whiteType) ? BreakTie(blackType, blackHand, whiteHand) :
        (blackType > whiteType) ? Winner::Black : Winner::White;
}

int execute(std::istream& in, std::ostream& out)
{
    std::array<card,handSize> blackHand;
    std::array<card,handSize> whiteHand;

    char rank, suit;
    auto assignCard{[&in, &rank](card& c) 
    { 
        in >> rank >> c.second; 
        c.first = rankToValue[rank];
    }};
    auto sortHand([](const card& c1, const card& c2) { return c1.first < c2.first; });

    while (in >> rank >> suit)
    {
        blackHand[0].first = rankToValue[rank];
        blackHand[0].second = suit;
        std::for_each(blackHand.begin() + 1, blackHand.end(), assignCard);
        std::for_each(whiteHand.begin(), whiteHand.end(), assignCard);
        std::sort(blackHand.begin(), blackHand.end(), sortHand);
        std::sort(whiteHand.begin(), whiteHand.end(), sortHand);
        auto blackType{ClassifyHand(blackHand)};
        auto whiteType{ClassifyHand(whiteHand)};
        const auto winner{ChooseWinner(blackType, blackHand, whiteType, whiteHand)};
        out << blackHand << whiteHand;
    }

    return 0;
}

int main(int argc, char* argv[])
{
    std::ios_base::sync_with_stdio(false);

    return (argc == 0) ?
        execute(std::cin, std::cout) :
        Catch::Session().run(argc, argv);
}
