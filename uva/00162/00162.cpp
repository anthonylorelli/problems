// Problem definition: https://uva.onlinejudge.org/external/1/162.pdf
// Accepted ?

#include <iostream>
#include <stack>
#include <deque>
#include <string>
#include <unordered_map>

std::unordered_map<char,int> rankMap 
{
    {{'A', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
    {'8', 8}, {'9', 9}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}}
};

class Card
{
public:
    Card(const char rank) : m_rank{rankMap[rank]}  { }

private:
    int m_rank;
};

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::stack<Card> nonDealer;
    std::stack<Card> dealer;

    std::string card;
    while (std::cin >> card && card[0] != '#')
    {
        nonDealer.push(Card{rankMap[card[1]]});
        for (int i {1}; i < 52; ++i)
        {
            auto& p {i % 2 ? dealer : nonDealer};
            std::cin >> card;
            p.push(Card{rankMap[card[1]]});
        }
    }
}