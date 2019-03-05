// Problem definition: https://uva.onlinejudge.org/external/4/462.pdf
// Accepted ?

#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main()
{
    std::ios_base::sync_with_stdio(false);
    constexpr int handSize {13};

    std::unordered_map<char,int> suits 
    {
        { {'H',0}, {'S',0}, {'C',0}, {'D',0} }
    };
    std::unordered_map<char,int> facePoints
    {
        { {'J',1}, {'Q',2}, {'K',3}, {'A',4}, {'2',0}, {'3',0}, {'4',0}, {'5',0},
        {'6',0}, {'7',0}, {'8',0}, {'9',0}, {'T',0} }
    };
    int points {0};

    std::pair<char,char> card;
    std::vector<std::pair<char,char>> hand;

    auto ProcessCard = [&](std::pair<char,char>& card)
    {
        points += facePoints[card.first];
        suits[card.second]++;
        hand.push_back(card);        
    };

    while (std::cin >> card.first && std::cin >> card.second)
    {
        ProcessCard(card);
        for (int i = 1; i < handSize; ++i)
        {
            std::cin >> card.first >> card.second;
            ProcessCard(card);
        }

        std::for_each(hand.begin(), hand.end(), [&](std::pair<char,char>& card) 
        {
            switch (card.first)
            {
                case 'K':
                    if (suits[card.second] == 1) { points--; }
                    break;
                case 'Q':
                    if (suits[card.second] <= 2) { points--; }
                    break;
                case 'J':
                    if (suits[card.second] <= 3) { points--; }
                    break;
            }
        });
    }
}