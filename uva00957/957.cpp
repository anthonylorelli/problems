// Problem definition:
// https://uva.onlinejudge.org/external/9/957.pdf

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int years {0};
    int popes {0};
    std::vector<int> electionYears;

    while (std::cin >> years)
    {
        std::cin >> popes;

        for (int i {0}; i < popes; ++i)
        {
            int year {0};
            std::cin >> year;
            electionYears.push_back(year);
        }

        int mostElections {0};
        int startingYear {0};
        int finalYear {0};

        for (size_t i {0}; i < electionYears.size(); ++i)
        {
            int limit {electionYears[i] + years};
            int lookAhead {0};

            while ((i + lookAhead < electionYears.size()) && (electionYears[i + lookAhead] < limit))
            {
                lookAhead++;
            }

            if (lookAhead > mostElections) 
            { 
                mostElections = lookAhead; 
                startingYear = electionYears[i];
                finalYear = electionYears[i + lookAhead - 1];
            }
        }

        std::cout << mostElections << " " << startingYear << " " << finalYear;
    }
}