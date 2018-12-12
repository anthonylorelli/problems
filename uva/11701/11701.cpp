// Problem definition: https://uva.onlinejudge.org/external/117/11701.pdf
// Cf. Ternary base converter: https://www.mathsisfun.com/numbers/convert-base.php?to=ternary
// Accepted ?

#include <iostream>
#include <math.h>
#include <string>
#include <vector>

constexpr char g_member[] {"MEMBER"};
constexpr char g_nonMember[] {"NON-MEMBER"};

const char* IsInCantorSet(const double input, int digit)
{
    if (digit == 6) 
    {
        //std::cout << "\n"; 
        return g_member; 
    }

    double rebase { input * 3 };
    double first { (rebase >= 1) ? floor(rebase) : 0.0 };

    //std::cout << first;

    if (first == 1) 
    {
        //std::cout << "\n";
        return g_nonMember;
    }
    else
    {
        return (first > 1) ? IsInCantorSet(rebase - first, digit + 1) :
            IsInCantorSet(rebase, digit);
    }
}

const char* IsInCantorSet(const double input)
{
    //std::cout << "0.";
    return IsInCantorSet(input, 0);
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    double input {0.0};

    while (std::cin.peek() != 'E' && std::cin >> input)
    {
        //std::cout << "Input: " << input << " Result: ";
        const char* output = (input == 1 || input == 0) ? g_member : IsInCantorSet(input);
        std::cout << output << "\n";
    }
}