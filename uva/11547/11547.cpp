// Problem definition: https://uva.onlinejudge.org/external/115/11547.pdf
// Accepted 2018-01-15

#include <iostream>
#include <math.h>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int cases {0};
    std::cin >> cases;

    while (cases--)
    {
        int n {0};
        std::cin >> n;

        int answer {((n * 315 + 36962) % 100) / 10};
        std::cout << abs(answer) << "\n";
    }
}
