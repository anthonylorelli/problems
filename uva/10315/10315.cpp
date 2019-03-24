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