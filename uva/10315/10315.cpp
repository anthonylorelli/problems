// Problem definition: https://uva.onlinejudge.org/external/103/10315.pdf
// Accepted ?

#include <array>
#include <tuple>
#include <iostream>
#include <algorithm>

constexpr size_t handSize{5};

std::ostream& operator<<(std::ostream& o, std::array<std::pair<char,char>,handSize> hand)
{
    o << "Hand: ";
    std::for_each(hand.begin(), hand.end(), [&o](std::pair<char,char>& c) { o << " " << c.first << c.second; });
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

bool IsNOfAKind(const std::array<std::pair<char,char>,handSize>& hand, const int n)
{
    int count{1};
    char rank{hand[0].first};
    std::for_each(hand.begin()+1, hand.end(), 
        [&count, &rank](const std::pair<char,char>& c) 
        {
            if (c.first == rank) { count++; } else { rank = c.first; count = 1; }
        });

    return count == n;
}

bool IsPair(const std::array<std::pair<char,char>,handSize>& hand)
{
    return IsNOfAKind(hand, 2);
}

bool IsThreeOfAKind(const std::array<std::pair<char,char>,handSize>& hand)
{
    return IsNOfAKind(hand, 3);
}

bool IsFullHouse(const std::array<std::pair<char,char>,handSize>& hand)
{
    return (hand[0].first == hand[1].first && hand[1].first == hand[2].first && hand[3].first == hand[4].first) ||
        (hand[0].first == hand[1].first && hand[2].first == hand[3].first && hand[3].first == hand[4].first);
}

bool IsFourOfAKind(const std::array<std::pair<char,char>,handSize>& hand)
{
    return IsNOfAKind(hand, 4);
}

bool IsFlush(std::array<std::pair<char,char>,handSize>& hand)
{
    char suit{hand[0].second};
    return std::all_of(hand.begin()+1, hand.end(), 
        [&suit](const std::pair<char,char>& c) { return c.second == suit; });
}

HandType ClassifyHand(std::array<std::pair<char,char>,handSize>& hand)
{
    return HandType::HighCard;
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::array<std::pair<char,char>,handSize> blackHand;
    std::array<std::pair<char,char>,handSize> whiteHand;

    char rank, suit;
    auto assignCard{[](std::pair<char,char>& c) { std::cin >> c.first >> c.second; }};
    auto sortHand([](std::pair<char,char>& c1, std::pair<char,char>& c2) { return c1.first < c2.first; });

    while (std::cin >> rank >> suit)
    {
        blackHand[0].first = rank;
        blackHand[0].second = suit;
        std::for_each(blackHand.begin() + 1, blackHand.end(), assignCard);
        std::for_each(whiteHand.begin(), whiteHand.end(), assignCard);
        std::sort(blackHand.begin(), blackHand.end(), sortHand);
        std::sort(whiteHand.begin(), whiteHand.end(), sortHand);
        std::cout << blackHand << whiteHand;
    }
}