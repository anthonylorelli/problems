// Problem definition: https://uva.onlinejudge.org/external/101/10141.pdf
// Accepted 2019-02-06

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

struct Proposal
{
    std::string Name;
    double Price;
    double Compliance;
    double Requirements;

    Proposal() : Price{0.0}, Compliance{0.0}, Requirements{0} {}
};

int main()
{
    std::ios_base::sync_with_stdio(false);

    int requirements {0};
    int proposals {0};
    int count {1};

    while (std::cin >> requirements >> proposals && !(requirements == 0 && proposals == 0))
    {
        std::string lineItem;
        for (int i {0}; i <= requirements; ++i) { std::getline(std::cin, lineItem); }

        std::vector<Proposal> submitted(proposals);
        std::for_each(submitted.begin(), submitted.end(),
            [&](Proposal& p) 
            { 
                std::getline(std::cin, p.Name);
                std::cin >> p.Price >> p.Requirements; 
                p.Compliance = p.Requirements / requirements; 
                for (int i {0}; i <= p.Requirements; ++i) { std::getline(std::cin, lineItem); }
            });

        int best {0};
        for (int i {1}; i < proposals; ++i)
        {
            if ((submitted[i].Compliance == submitted[best].Compliance &&
                submitted[i].Price < submitted[best].Price) ||
                submitted[i].Compliance > submitted[best].Compliance)
            {
                best = i;
            }
        }

        if (count > 1) { std::cout << "\n"; }
        std::cout << "RFP #" << count++ << "\n" << submitted[best].Name << "\n";
    }
}
