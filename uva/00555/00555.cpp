// Problem definition: https://uva.onlinejudge.org/external/5/555.pdf
// Accepted ?

#include <array>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
#include <unordered_map>

void PrintHand(const std::pair<char,char>& s)
{
    std::cout << " " << s.first << s.second;
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    constexpr int deckSize{52};
    constexpr int players{4};

    std::unordered_map<char,int> playerIndex{ {'N', 0}, {'E', 1}, {'S', 2}, {'W', 3} };
    std::unordered_map<char,int> suit{ {'C', 0}, {'D', 1}, {'S', 2}, {'H', 3} };
    std::unordered_map<char,int> face{ {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, 
        {'8', 8}, {'9', 9}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14} };

    char next;
    int counter{0};

    while (std::cin >> next && next != '#')
    {
        std::array<std::vector<std::pair<char,char>>, players> hands;
        std::pair<char,char> card;
        for (size_t i{(playerIndex[next]+1) % playerIndex.size()}, j{0}; j < deckSize; ++j)
        {
            std::cin >> card.first >> card.second;
            hands[i].emplace_back(card);
            i = (i + 1) % playerIndex.size();
        }

        std::for_each(hands.begin(), hands.end(), 
            [&](std::vector<std::pair<char,char>>& hand)
            {
                std::sort(hand.begin(), hand.end(), 
                    [&](std::pair<char,char>& a, std::pair<char,char>& b)
                    {
                        return (suit[a.first] == suit[b.first]) ? face[a.second] < face[b.second] :
                            suit[a.first] < suit[b.first];
                    });
            });

        if (counter++) { std::cout << "\n"; }
        std::vector<std::pair<const char*,char>> list{ {"S:", 'S'}, {"\nW:", 'W'}, {"\nN:", 'N'}, {"\nE:", 'E'} };
        std::for_each(list.begin(), list.end(), [&hands, &playerIndex](std::pair<const char*,char>& p)
            {
                std::cout << p.first;
                auto& h{hands[playerIndex[p.second]]};
                std::for_each(h.begin(), h.end(), PrintHand);
            });
    }
}