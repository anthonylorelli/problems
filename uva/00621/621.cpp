// Problem definition: https://uva.onlinejudge.org/external/6/621.pdf
// Accepted 2019-01-21

#include <iostream>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int cases {0};
    std::cin >> cases;
    std::string result;

    while (cases--)
    {
        std::cin >> result;

        if (result == "1" || result == "4" || result == "78")
        {
            std::cout << "+\n";
        }
        else 
        {
            auto size {result.size()};
            if (size >= 3 && result.substr(size - 2, 2) == "35")
            {
                std::cout << "-\n";
            }
            else if (size >= 3 && result[0] == '9' && result[size-1] == '4')
            {
                std::cout << "*\n";
            }
            else if (size >=4 && result.substr(0, 3) == "190")
            {
                std::cout << "?\n";
            }
        }
    }
}
