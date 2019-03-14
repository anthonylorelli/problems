// Problem definition: https://uva.onlinejudge.org/external/5/555.pdf
// Accepted ?

#include <iostream>
#include <tuple>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    constexpr int deckSize{52};
    constexpr int players{4};
    std::vector<std::pair<char,char>> hands[players];
    char next;

    while (std::cin >> next && next != '#')
    {
        std::pair<char,char> card;
        for (int i{0}; i < deckSize; ++i)
        {
            std::cin >> card.first >> card.second;
        }
    }
}