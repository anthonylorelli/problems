// Problem definition: https://uva.onlinejudge.org/external/1/162.pdf
// Accepted ?

#include <iostream>
#include <deque>
#include <string>
#include <unordered_map>
#include <algorithm>

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

std::deque<Card>* RespondToFace(std::deque<Card>& p1, std::deque<Card>& p2, std::deque<Card>& pile)
{
    int draw {CalculateDraw(pile)};

    for (int i {0}; i < draw && p1.size() > 0; ++i)
    {
        pile.push_front(p1.front());
        p1.pop_front();

        Card c {pile.front()};
        if (c >= Jack) 
        { 
            return RespondToFace(p2, p1, pile);
        }
    }

    return &p2;
}

std::deque<Card>* StartGame(std::deque<Card>& p1, std::deque<Card>& p2, std::deque<Card>& pile)
{
    if (p1.size() > 0)
    {
        pile.push_front(p1.front());
        p1.pop_front();

        Card c {pile.front()};
        return (c >= Jack) ? RespondToFace(p2, p1, pile) : StartGame(p2, p1, pile);
    }
    else
    {
        return &p2;
    }    
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::string card;
    while (std::cin >> card && card[0] != '#')
    {
        std::deque<Card> dealer;        
        std::deque<Card> nonDealer;

        nonDealer.push_front(Card{card[0], card[1]});

        for (int i {1}; i < 52; ++i)
        {
            auto& p {i % 2 ? dealer : nonDealer};
            std::cin >> card;
            p.push_front(Card{card[0], card[1]});
        }

        std::deque<Card> pile;

        std::deque<Card>* startingPlayer {&nonDealer};
        std::deque<Card>* secondTurn {&dealer};
        while (dealer.size() > 0 && nonDealer.size() > 0)
        {
            std::cout << "\nDealer " << dealer.size() << ": ";
            std::for_each(dealer.begin(), dealer.end(), [](Card& c) { std::cout << c.ToString() << " "; });
            std::cout << "\nNon-dealer " << nonDealer.size() << ": ";
            std::for_each(nonDealer.begin(), nonDealer.end(), [](Card& c) { std::cout << c.ToString() << " "; });
            std::cout << "\n";
            std::deque<Card>* winner {StartGame(*startingPlayer, *secondTurn, pile)};
            if (winner->size() + pile.size() == 52) { break; }
            std::move(pile.rbegin(), pile.rend(), std::back_inserter(*winner));
            pile.clear();
            std::cout << "\nWinner: " << ((winner == &dealer) ? "dealer" : "non-dealer") << "\n";
            if (winner != startingPlayer) { std::swap(startingPlayer, secondTurn); }
        }

        std::cout << (dealer.size() ? "1 " : "2 ") << (dealer.size() ? dealer.size() : nonDealer.size()) << "\n";
    }
}