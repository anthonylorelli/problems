// Problem definition: https://uva.onlinejudge.org/external/1/119.pdf
// Accepted ?

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int people {0};

    while (std::cin >> people)
    {
        std::vector<std::string> names(people);
        std::for_each(names.begin(), names.end(), [](std::string& s) { std::cin >> s; });
    }
}
