// Problem definition: https://uva.onlinejudge.org/external/4/462.pdf
// Accepted 2019-03-11

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
        { {'S',0}, {'H',0}, {'D',0}, {'C',0} }
    };
    std::unordered_map<char,bool> stopped
    {
        { {'S',false}, {'H',false}, {'D',false}, {'C',false} }
    };
    std::unordered_map<char,int> facePoints
    {
        { {'J',1}, {'Q',2}, {'K',3}, {'A',4}, {'2',0}, {'3',0}, {'4',0}, {'5',0},
        {'6',0}, {'7',0}, {'8',0}, {'9',0}, {'T',0} }
    };

    int noTrumpPoints {0};
    std::pair<char,char> card;
    std::vector<std::pair<char,char>> hand;

    auto ProcessCard = [&](std::pair<char,char>& card)
    {
        noTrumpPoints += facePoints[card.first];
        suits[card.second]++;
        hand.push_back(card);        
    };

    while (std::cin >> card.first && std::cin >> card.second)
    {
        noTrumpPoints = 0;
        hand.clear();
        std::for_each(suits.begin(), suits.end(), [](std::pair<const char,int>& s) { s.second = 0; });
        std::for_each(stopped.begin(), stopped.end(), [](std::pair<const char,bool>& s) { s.second = false; });
        
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
                case 'A':
                    stopped[card.second] = true;
                    break;
                case 'K':
                    if (suits[card.second] == 1) { noTrumpPoints--; }
                    else if (suits[card.second] > 1) { stopped[card.second] = true; }
                    break;
                case 'Q':
                    if (suits[card.second] <= 2) { noTrumpPoints--; }
                    else if (suits[card.second] > 2) { stopped[card.second] = true; }
                    break;
                case 'J':
                    if (suits[card.second] <= 3) { noTrumpPoints--; }
                    break;
            }
        });

        int points {noTrumpPoints};

        std::for_each(suits.begin(), suits.end(), [&](std::pair<const char,int>& suit)
        {
            if (suit.second == 2)
            {
                points++;
            }
            else if (suit.second == 1)
            {
                points += 2;
            }
            else if (suit.second == 0)
            {
                points += 2;
            }
        });

        if (points < 14)
        {
            std::cout << "PASS\n";
        }
        else if (noTrumpPoints >= 16 && stopped['H'] && stopped['D'] && stopped['S'] && stopped['C'])
        {
            std::cout << "BID NO-TRUMP\n";
        }
        else
        {
            const char* s = (suits['S'] >= suits['H'] && suits['S'] >= suits['D'] && suits['S'] >= suits['C']) ?
                "S" : (suits['H'] >= suits['D'] && suits['H'] >= suits['C']) ? 
                "H" : (suits['D'] >= suits['C']) ?
                "D" : "C";
            
            std::cout << "BID " << s << "\n";
        }        
    }
}