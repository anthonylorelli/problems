// Problem definition: https://uva.onlinejudge.org/external/102/10205.pdf
// Accepted ?

#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
#include <deque>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int cases{0};
    std::cin >> cases;

    size_t numShuffles{0};
    constexpr size_t deckSize{52};
    std::deque<std::pair<char,char>> deck{deckSize};

    while (cases--)
    {
        std::cin >> numShuffles;
        std::vector<std::vector<int>> shuffles{numShuffles};
        std::for_each(shuffles.begin(), shuffles.end(),
            [&deckSize](std::vector<int>& v) 
            { 
                int n;
                std::generate_n(std::back_inserter(v), deckSize,
                    [&n]() { std::cin >> n; return n; });
            });

        std::string s;
        while (std::getline(std::cin, s) && s.length() > 0)
        {
            int shuffle{std::stoi(s)};
            std::vector<int>& v{shuffles[shuffle]};
            std::for_each(v.begin(), v.end(),
                [&deck](int n) {});
        }
    }
}