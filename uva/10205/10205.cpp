// Problem definition: https://uva.onlinejudge.org/external/102/10205.pdf
// Accepted ?

#include <algorithm>
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

std::deque<std::pair<char,char>> const startingDeck{
    {'2','C'}, {'3','C'},{'4','C'}, {'5','C'},{'6','C'}, {'7','C'},{'8','C'}, {'9','C'},{'T','C'}, {'J','C'},{'Q','C'}, {'K','C'}, {'A','C'},
    {'2','D'}, {'3','D'},{'4','D'}, {'5','D'},{'6','D'}, {'7','D'},{'8','D'}, {'9','D'},{'T','D'}, {'J','D'},{'Q','D'}, {'K','D'}, {'A','D'},
    {'2','H'}, {'3','H'},{'4','H'}, {'5','H'},{'6','H'}, {'7','H'},{'8','H'}, {'9','H'},{'T','H'}, {'J','H'},{'Q','H'}, {'K','H'}, {'A','H'},
    {'2','S'}, {'3','S'},{'4','S'}, {'5','S'},{'6','S'}, {'7','S'},{'8','S'}, {'9','S'},{'T','S'}, {'J','S'},{'Q','S'}, {'K','S'}, {'A','S'}
};

int main()
{
    std::ios_base::sync_with_stdio(false);

    int cases{0};
    std::cin >> cases;

    constexpr size_t deckSize{52};
    std::deque<std::pair<char,char>> deck{deckSize};
    size_t numShuffles{0};

    while (cases--)
    {
        deck = startingDeck;
        std::cin >> numShuffles;
        std::vector<std::vector<size_t>> shuffles{numShuffles};
        std::for_each(shuffles.begin(), shuffles.end(),
            [&deckSize](std::vector<size_t>& v) 
            { 
                size_t n;
                std::generate_n(std::back_inserter(v), deckSize,
                    [&n]() { std::cin >> n; return n; });
            });

        std::string s;
        while (std::getline(std::cin, s) && s.length() > 0)
        {
            int shuffle{std::stoi(s)};
            std::vector<size_t>& v{shuffles[shuffle - 1]};
            for (size_t j{0}; j < deckSize; ++j)
            {
                size_t i{v[j] - 1};
                if (i != j)
                {
                    std::pair<char,char> c{deck[i]};
                    deck.erase(deck.begin() + i);
                    deck.insert(deck.begin() + j, c);
                }
            }
        }

        std::for_each(deck.begin(), deck.end(), 
            [&deck](std::pair<char,char>& c) { std::cout << c; });
    }
}