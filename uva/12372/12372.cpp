// Problem definition: https://uva.onlinejudge.org/external/123/12372.pdf
// Accepted ?

#include <iostream>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int cases {0};
    int counter {1};

    while (cases--)
    {
        int length {0};
        int width {0};
        int height {0};

        std::cin >> length >> width >> height;

        std::string result {"bad"};

        std::cout << "Case " << counter++ << ": " << result << "\n";
    }
}
