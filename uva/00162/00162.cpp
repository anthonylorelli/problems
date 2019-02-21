// Problem definition: https://uva.onlinejudge.org/external/1/162.pdf
// Accepted ?

#include <iostream>
#include <deque>
#include <string>
#include <unordered_map>
#include <algorithm>

std::unordered_map<char,int> rankMap 
{
    {{'A', 14}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
    {'8', 8}, {'9', 9}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}}
};

class Card
{
public:
    Card(const char rank) : m_rank{rankMap[rank]}  { }

    bool operator<=(const Card& c)
    {
        return m_rank <= c.m_rank;
    }

    bool operator>=(const Card& c)
    {
        return m_rank >= c.m_rank;
    }

    bool operator==(const Card& c)
    {
        return m_rank == c.m_rank;
    }

private:
    int m_rank;
};

const Card Jack{'J'};
const Card Queen{'Q'};
const Card King{'K'};
const Card Ace{'A'};

void ExecuteTurn(std::deque<Card>& p1, std::deque<Card>& p2, std::deque<Card>& pile)
{
    pile.push_front(p1.front());
    p1.pop_front();

    Card& top{pile.front()};
    int deals = (top == Jack) ? 1 : (top == Queen) ? 2 : (top == King) ? 3 : (top == Ace) ? 4 : 1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::string card;
    while (std::cin >> card && card[0] != '#')
    {
        std::deque<Card> dealer;        
        std::deque<Card> nonDealer;
        nonDealer.push_front(Card{rankMap[card[1]]});

        for (int i {1}; i < 52; ++i)
        {
            auto& p {i % 2 ? dealer : nonDealer};
            std::cin >> card;
            p.push_front(Card{rankMap[card[1]]});
        }

        std::deque<Card> pile;

        std::deque<Card>* p1{&nonDealer};
        std::deque<Card>* p2{&dealer};

        while (dealer.size() != 0 && nonDealer.size() != 0)
        {
            ExecuteTurn(*p1, *p2, pile);
        }
    }
}