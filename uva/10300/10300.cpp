// Problem definition: https://uva.onlinejudge.org/external/103/10300.pdf
// Accepted 2019-01-21

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int cases {0};
    std::cin >> cases;

    while (cases--)
    {
        int farmers {0};
        std::cin >> farmers;

        int farmyard {0};
        int animals {0};
        int friendliness {0};
        double totalPayment {0.0};

        while (farmers--)
        {
            std::cin >> farmyard >> animals >> friendliness;
            auto spaceQuota {animals ? static_cast<double>(farmyard) / animals : 0.0};
            auto premiumPerAnimal {spaceQuota * friendliness};
            auto amountOwed {premiumPerAnimal * animals};
            totalPayment += amountOwed;
        }

        std::cout << static_cast<unsigned long long>(totalPayment) << "\n";
    }
}
