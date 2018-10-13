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

        std::vector<int> total;
        std::vector<int> first;
        std::vector<int> last;

        int elections {0};
        int firstElection {0};
        int lastElection {0};

        for (int i {0}; i < electionYears.size(); ++i)
        {
            for (int j {0}; j < years; ++j)
            {
                if (j == 0) { firstElection = electionYears[i]; }
                else if (j == years - 1) { lastElection = electionYears[i + j];}
            }
        }
    }
}