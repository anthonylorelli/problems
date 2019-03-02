// Problem definition: https://uva.onlinejudge.org/external/1/162.pdf
// Accepted 2019-03-02

#include <iostream>
#include <deque>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <tuple>

std::unordered_map<char,int> rankMap 
{
    {{'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, 
    {'9', 9}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}}
};

class Card
{
public:
    Card(const char rank) : m_suit{'_'}, m_rank{rankMap[rank]} { }
    Card(const char suit, const char rank) : m_suit{suit}, m_rank{rankMap[rank]}  { }

    bool operator<=(const Card& c) const { return m_rank <= c.m_rank; }
    bool operator>=(const Card& c) const { return m_rank >= c.m_rank; }
    bool operator==(const Card& c) const { return m_rank == c.m_rank; }

    std::string ToString() { return m_suit + std::to_string(m_rank); }

private:
    char m_suit;
    int m_rank;
};

const Card Jack{'J'};
const Card Queen{'Q'};
const Card King{'K'};
const Card Ace{'A'};

int CalculateDraw(std::deque<Card>& pile)
{
    if (pile.size() == 0) { return 1; }

    Card c {pile.front()};

    return (c == Jack) ? 1 : (c == Queen) ? 2 : (c == King) ? 3 : (c == Ace) ? 4 : 1;
}

std::pair<bool,std::deque<Card>*> CoverFace(std::deque<Card>& p1, std::deque<Card>& p2, std::deque<Card>& pile)
{
    int draw {CalculateDraw(pile)};

    for (int i {0}; i < draw; ++i)
    {
        if (p1.size() == 0) { return std::make_pair(false, &p2); }

        pile.push_front(p1.front());
        p1.pop_front();

        Card c {pile.front()};
        if (c >= Jack) 
        { 
            return CoverFace(p2, p1, pile);
        }
    }

    return std::make_pair(true, &p2);
}

std::pair<bool,std::deque<Card>*> PlayGame(std::deque<Card>& p1, std::deque<Card>& p2, std::deque<Card>& pile)
{
    if (p1.size() == 0) { return std::make_pair(false, &p2); }

    pile.push_front(p1.front());
    p1.pop_front();

    Card c {pile.front()};
    return (c >= Jack) ? CoverFace(p2, p1, pile) : PlayGame(p2, p1, pile);
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    constexpr int deckSize {52};

    std::string card;
    while (std::cin >> card && card[0] != '#')
    {
        std::deque<Card> dealer;        
        std::deque<Card> nonDealer;

        nonDealer.push_front(Card{card[0], card[1]});

        for (int i {1}; i < deckSize; ++i)
        {
            auto& p {i % 2 ? dealer : nonDealer};
            std::cin >> card;
            p.push_front(Card{card[0], card[1]});
        }

        std::deque<Card> pile;
        std::deque<Card>* startingPlayer {&nonDealer};
        std::deque<Card>* secondTurn {&dealer};
        std::pair<bool, std::deque<Card>*> result;

        while (true)
        {
            result = PlayGame(*startingPlayer, *secondTurn, pile);
            if (!result.first) { break; }
            std::move(pile.rbegin(), pile.rend(), std::back_inserter(*result.second));
            pile.clear();
            if (result.second != startingPlayer) { std::swap(startingPlayer, secondTurn); }
        }

        std::cout << (result.second == &dealer ? "1" : "2") << std::right << std::setw(3) << 
            (result.second == &dealer ? dealer.size() : nonDealer.size()) << "\n";
    }
}