// Problem definition: https://uva.onlinejudge.org/external/1/119.pdf
// Accepted 2019-02-04

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int people {0};
    int instance {1};

    while (std::cin >> people)
    {
        std::vector<std::string> names(people);
        std::unordered_map<std::string, int> worth;
        std::for_each(names.begin(), names.end(), [&](std::string& s) { std::cin >> s; worth[s] = 0; });

        for (int i {0}; i < people; ++i)
        {
            std::string person; 
            int balance {0};
            int recipients {0};
            std::cin >> person >> balance >> recipients;

            if (recipients > 0)
            {
                int share {balance / recipients};
                worth[person] -= (share * recipients);

                for (int j {0}; j < recipients; ++j)
                {
                    std::cin >> person;
                    worth[person] += share;
                }
            }
        }

        if (instance++ > 1) { std::cout << "\n"; }

        for (auto& name : names)
        {
            std::cout << name << " " << worth[name] << "\n";
        }
    }
}
