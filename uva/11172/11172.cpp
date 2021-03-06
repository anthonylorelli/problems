// Problem definition: https://uva.onlinejudge.org/external/111/11172.pdf
// Accepted 2019-01-01

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int cases {0};
    int a {0};
    int b {0};
    std::cin >> cases;

    while (cases--)
    {
        std::cin >> a >> b;
        std::cout << ((a > b) ? ">" : (a < b) ? "<" : "=") << "\n";
    }
}
