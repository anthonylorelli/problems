// Problem definition: https://uva.onlinejudge.org/external/117/11701.pdf
// Accepted ?

#include <iostream>
#include <string>
#include <vector>

constexpr char g_member[] {"MEMBER"};
constexpr char g_nonMember[] {"NON-MEMBER"};

const char* IsInCantorSet(const float input, int digit)
{
    if (digit == 6) { return g_member; }

    float rebase { input * 3 };
    float first { std::floor(rebase) };

    return (first == 1) ? g_nonMember : IsInCantorSet(rebase - first, digit + 1);
}

const char* IsInCantorSet(const float input)
{
    return IsInCantorSet(input, 0);
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    float input {0.0};

    while (std::cin.peek() != 'E' && std::cin >> input)
    {
        const char* output = (input == 1 || input == 0) ? g_member : IsInCantorSet(input);
        std::cout << output << "\n";
    }
}