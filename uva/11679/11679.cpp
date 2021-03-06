// Problem definition: https://uva.onlinejudge.org/external/116/11679.pdf
// Accepted 2019-01-29

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int banks {0};
    int debentures {0};

    while ((std::cin >> banks >> debentures) && !(banks == 0 && debentures == 0))
    {
        std::vector<int> reserves(banks);

        for (int i = 0; i < banks; ++i)
        {
            int reserve {0}; 
            std::cin >> reserve; 
            reserves[i] = reserve; 
        }

        int debtor {0}; int creditor {0}; int value {0};

        while (debentures--)
        {
            std::cin >> debtor >> creditor >> value;
            reserves[debtor-1] -= value;
            reserves[creditor-1] += value;
        }

        auto result {std::find_if(std::begin(reserves), std::end(reserves),
            [](int r) { return r < 0; })};

        std::cout << (result != std::end(reserves) ? "N" : "S") << "\n";
    }
}
