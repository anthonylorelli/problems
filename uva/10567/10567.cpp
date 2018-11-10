// Problem definition: https://uva.onlinejudge.org/external/105/10567.pdf
// Accepted: ?

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    int n {0};
    std::cin >> n;

    while (n--)
    {
        std::string candidates;
        std::cin >> candidates;

        std::cout << candidates << "\n";
    }
}