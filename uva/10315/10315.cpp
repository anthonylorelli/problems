// Problem definition: https://uva.onlinejudge.org/external/103/10315.pdf
// Accepted ?

#include <array>
#include <tuple>
#include <iostream>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);

    constexpr size_t handSize{5};

    std::array<std::pair<char,char>,handSize> blackHand;
    std::array<std::pair<char,char>,handSize> whiteHand;

    char rank, suit;
    auto assignCard{[](std::pair<char,char>& c) { std::cin >> c.first >> c.second; }};

    while (std::cin >> rank >> suit)
    {
        blackHand[0].first = rank;
        blackHand[0].second = suit;
        std::for_each(blackHand.begin() + 1, blackHand.end(), assignCard);
        std::for_each(whiteHand.begin(), whiteHand.end(), assignCard);
    }
}