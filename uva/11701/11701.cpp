// Problem definition: https://uva.onlinejudge.org/external/117/11701.pdf
// Accepted ?

#include <iostream>
#include <string>
#include <vector>

constexpr char g_member[] {"MEMBER"};
constexpr char g_nonMember[] {"NON-MEMBER"};

const char* IsInCantorSet(const std::string& number)
{
    return g_nonMember;
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::string input;

    while (std::cin >> input && input != "END")
    {
        const char* output = (input == "1" || input == "0") ? g_member : IsInCantorSet(input);
        std::cout << output << "\n";
    }
}