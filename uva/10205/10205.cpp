// Problem definition: https://uva.onlinejudge.org/external/102/10205.pdf
// Accepted ?

#include <iostream>
#include <tuple>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int cases{0};
    std::cin >> cases;

    int numShuffles{0};
    constexpr int deckSize{52};
    std::vector<std::pair<char,char>> deck(deckSize);

    while (cases--)
    {
        std::cin >> numShuffles;
    }
}