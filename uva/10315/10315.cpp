// Problem definition: https://uva.onlinejudge.org/external/103/10315.pdf
// Accepted ?

#include <array>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <unordered_map>

constexpr size_t handSize{5};

std::unordered_map<char,int> rankToValue{
    {'2',2}, {'3',3}, {'4',4},{'5',5}, {'6',6}, {'7',7}, {'8',8}, 
    {'9',9}, {'T',10},{'J',11}, {'Q',12}, {'K',13}, {'A', 14}
};

std::unordered_map<int,char> valueToRank{
    {2,'2'}, {3,'3'}, {4,'4'},{5,'5'}, {6,'6'}, {7,'7'}, {8,'8'}, 
    {9,'9'}, {10,'T'}, {11,'J'}, {12,'Q'}, {13,'K'}, {14,'A'}
};

std::ostream& operator<<(std::ostream& o, std::array<std::pair<int,char>,handSize> hand)
{
    o << "Hand: ";
    std::for_each(hand.begin(), hand.end(), [&o](std::pair<int,char>& c) { o << " " << valueToRank[c.first] << c.second; });
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

bool IsNOfAKind(const std::array<std::pair<int,char>,handSize>& hand, const int n)
{
    int count{1};
    int rank{hand[0].first};
    std::for_each(hand.begin()+1, hand.end(), 
        [&count, &rank](const std::pair<int,char>& c) 
        {
            if (c.first == rank) { count++; } else { rank = c.first; count = 1; }
        });

    return count == n;
}

bool IsTwoPairs(const std::array<std::pair<int,char>,handSize>& hand)
{
    auto findPair{[](const std::pair<int,char>& c1, const std::pair<int,char>& c2) { return c1.first == c2.first; }};
    auto first{std::adjacent_find(hand.begin(), hand.end(), findPair)};
    auto second{(first != hand.end() && first + 2 != hand.end()) ?
        std::adjacent_find(first+2, hand.end(), findPair) : hand.end()};
    return second != hand.end();
}

bool IsStraight(const std::array<std::pair<int,char>,handSize>& hand)
{
    int rank{hand[0].first + 1};
    return std::all_of(hand.begin()+1, hand.end(), 
        [&rank](const std::pair<int,char> c) { return c.first == rank++; });
}

bool IsStraightFlush(const std::array<std::pair<int,char>,handSize>& hand)
{
    int rank{hand[0].first + 1};
    char suit{hand[0].second};
    return std::all_of(hand.begin()+1, hand.end(),
        [&rank, &suit](const std::pair<int,char> c) { return c.first == rank++ && c.second == suit; });
}

std::pair<int,char> HighCard(const std::array<std::pair<int,char>,handSize>& hand)
{
    return std::make_pair<int,char>('\0','\0');
}

bool IsPair(const std::array<std::pair<int,char>,handSize>& hand)
{
    return IsNOfAKind(hand, 2);
}

bool IsThreeOfAKind(const std::array<std::pair<int,char>,handSize>& hand)
{
    return IsNOfAKind(hand, 3);
}

bool IsFullHouse(const std::array<std::pair<int,char>,handSize>& hand)
{
    return (hand[0].first == hand[1].first && hand[1].first == hand[2].first && hand[3].first == hand[4].first) ||
        (hand[0].first == hand[1].first && hand[2].first == hand[3].first && hand[3].first == hand[4].first);
}

bool IsFourOfAKind(const std::array<std::pair<int,char>,handSize>& hand)
{
    return IsNOfAKind(hand, 4);
}

bool IsFlush(const std::array<std::pair<int,char>,handSize>& hand)
{
    const char suit{hand[0].second};
    return std::all_of(hand.begin()+1, hand.end(), 
        [&suit](const std::pair<int,char>& c) { return c.second == suit; });
}

HandType ClassifyHand(const std::array<std::pair<int,char>,handSize>& hand)
{
    return HandType::HighCard;
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::array<std::pair<int,char>,handSize> blackHand;
    std::array<std::pair<int,char>,handSize> whiteHand;

    char rank, suit;
    auto assignCard{[&rank](std::pair<int,char>& c) 
    { 
        std::cin >> rank >> c.second; 
        c.first = rankToValue[rank];
    }};
    auto sortHand([](const std::pair<int,char>& c1, const std::pair<int,char>& c2) { return c1.first < c2.first; });

    while (std::cin >> rank >> suit)
    {
        blackHand[0].first = rankToValue[rank];
        blackHand[0].second = suit;
        std::for_each(blackHand.begin() + 1, blackHand.end(), assignCard);
        std::for_each(whiteHand.begin(), whiteHand.end(), assignCard);
        std::sort(blackHand.begin(), blackHand.end(), sortHand);
        std::sort(whiteHand.begin(), whiteHand.end(), sortHand);
        std::cout << blackHand << whiteHand;
    }
}
