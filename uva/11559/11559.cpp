// Problem definition: https://uva.onlinejudge.org/external/115/11559.pdf
// Accepted 2019-01-27

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);

    constexpr int tooExpensive {500001};

    int participants {0};
    int budget {0};
    int hotels {0};
    int weeks {0};

    while (std::cin >> participants >> budget >> hotels >> weeks)
    {
        int cost {tooExpensive};

        while (hotels--)
        {
            int price {0};
            std::cin >> price;

            for (int i = 0; i < weeks; ++i)
            {
                int beds {0};
                std::cin >> beds;

                if (beds >= participants)
                {
                    int estimate {price * participants};
                    if (estimate <= budget && estimate < cost)
                    {
                        cost = estimate;
                    }
                }
            }
        }

        if (cost < tooExpensive) 
        { 
            std::cout << cost << "\n"; 
        }
        else 
        { 
            std::cout << "stay home\n"; 
        }
    }
}
