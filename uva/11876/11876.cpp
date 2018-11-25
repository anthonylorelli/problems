// Problem definition: https://uva.onlinejudge.org/external/118/11876.pdf
// Accepted ?

#include <iostream>
#include <vector>

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