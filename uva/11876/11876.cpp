// Problem definition: https://uva.onlinejudge.org/external/118/11876.pdf
// Accepted ?

#include <iostream>
#include <vector>

void GenerateNodSequence(std::vector<int>& sequence)
{
    // n0 = 1
    // ni = n(i-1) + NOD(n(i-1))
    // 1 2 4 7 9 12
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int cases {0};
    std::cin >> cases;

    while (--cases)
    {
        int rangeStart {0};
        int rangeEnd {0};
        std::cin >> rangeStart >> rangeEnd;
        std::cout << rangeStart << " " << rangeEnd << "\n";
    }
}