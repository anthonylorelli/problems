// Problem definition: https://uva.onlinejudge.org/external/113/11332.pdf
// Accepted 2019-01-25

#include <iostream>

int Reduce(int value)
{
    int sum {0};

    while (value > 0)
    {
        sum += value % 10;
        value /= 10;
    }

    return sum >= 10 ? Reduce(sum) : sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    int value {0};
    
    while (std::cin >> value && value)
    {
        std::cout << Reduce(value) << "\n";
    }
}
