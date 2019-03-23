// Problem definition: https://uva.onlinejudge.org/external/102/10205.pdf
// Accepted 2019-03-22

#include <algorithm>
#include <array>
#include <iostream>
#include <tuple>
#include <vector>
#include <deque>
#include <string>

std::ostream& operator<<(std::ostream& o, std::pair<char,char>& p)
{
    switch (p.first)
    {
        case '2': case '3': case '4': case '5': 
        case '6': case '7': case '8': case '9':
            o << p.first;
            break;
        case 'T':
            o << "10";
            break;
        case 'J':
            o << "Jack";
            break;
        case 'Q':
            o << "Queen";
            break;
        case 'K':
            o << "King";
            break;
        case 'A':
            o << "Ace";
            break;
    }
    o << " of ";
    switch (p.second)
    {
        case 'C':
            o << "Clubs";
            break;
        case 'D':
            o << "Diamonds";
            break;
        case 'H':
            o << "Hearts";
            break;
        case 'S':
            o << "Spades";
            break;
    }
    o << "\n";
    return o;
}

constexpr size_t deckSize{52};
constexpr std::array<std::pair<char,char>, deckSize> referenceDeck{
    {{'2','C'}, {'3','C'}, {'4','C'}, {'5','C'}, {'6','C'}, {'7','C'}, {'8','C'}, {'9','C'}, {'T','C'}, {'J','C'}, {'Q','C'}, {'K','C'}, {'A','C'},
    {'2','D'}, {'3','D'}, {'4','D'}, {'5','D'}, {'6','D'}, {'7','D'}, {'8','D'}, {'9','D'}, {'T','D'}, {'J','D'}, {'Q','D'}, {'K','D'}, {'A','D'},
    {'2','H'}, {'3','H'}, {'4','H'}, {'5','H'}, {'6','H'}, {'7','H'}, {'8','H'}, {'9','H'}, {'T','H'}, {'J','H'}, {'Q','H'}, {'K','H'}, {'A','H'},
    {'2','S'}, {'3','S'}, {'4','S'}, {'5','S'}, {'6','S'}, {'7','S'}, {'8','S'}, {'9','S'}, {'T','S'}, {'J','S'}, {'Q','S'}, {'K','S'}, {'A','S'}}
};

int main()
{
    std::ios_base::sync_with_stdio(false);

    int cases{0};
    std::cin >> cases;

    std::array<std::pair<char,char>, deckSize> deck1;
    std::array<std::pair<char,char>, deckSize> deck2;
    size_t numShuffles{0};
    bool first{true};

    while (cases--)
    {
        deck1 = referenceDeck;
        std::cin >> numShuffles;
        std::vector<std::vector<size_t>> shuffles{numShuffles};
        std::for_each(shuffles.begin(), shuffles.end(),
            [](std::vector<size_t>& v) 
            { 
                size_t n;
                std::generate_n(std::back_inserter(v), deckSize,
                    [&n]() { std::cin >> n; return n - 1; });
            });

        std::array<std::pair<char,char>, deckSize>* d1{&deck1};
        std::array<std::pair<char,char>, deckSize>* d2{&deck2};

        std::string s; std::getline(std::cin, s);
        while (std::getline(std::cin, s) && s.length() > 0)
        {
            int shuffle{std::stoi(s)};
            std::vector<size_t>& v{shuffles[shuffle - 1]};
            for (size_t j{0}; j < deckSize; ++j)
            {
                size_t i{v[j]};
                (*d2)[j] = (*d1)[i];
            }

            std::swap(d1, d2);
        }

        if (!first) { std::cout << "\n"; } else { first = false; }
        std::for_each(d1->begin(), d1->end(), [](std::pair<char,char>& c) { std::cout << c; });
    }
}
