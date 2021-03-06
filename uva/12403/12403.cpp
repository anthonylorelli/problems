// Problem definition: https://uva.onlinejudge.org/external/124/12403.pdf
// Accepted 2019-01-21

#include <iostream>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int cases {0};
    std::cin >> cases;

    int total {0};
    std::string action;

    while (cases--)
    {
        std::cin >> action;

        if (action == "report")
        {
            std::cout << total << '\n';
        }
        else
        {
            int donation {0};
            std::cin >> donation;
            total += donation;
        }
    }
}
