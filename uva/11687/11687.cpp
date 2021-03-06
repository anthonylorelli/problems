// Problem definition: https://uva.onlinejudge.org/external/116/11687.pdf
// Accepted 2019-02-15

#include <iostream>
#include <string>

int Converge(const int i, const std::string& s)
{
    size_t digits {s.size()};
    std::string next {std::to_string(digits)};

    return next == s ? i : Converge(i+1, next);
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::string s;
    while (std::cin >> s && s[0] != 'E')
    {
        std::cout << Converge(1, s) << "\n";
    }
}
