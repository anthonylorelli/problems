// Problem definition: https://uva.onlinejudge.org/external/123/12372.pdf
// Accepted 2019-01-21

#include <iostream>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int cases {0};
    int counter {1};

    std::cin >> cases;

    while (cases--)
    {
        int length {0};
        int width {0};
        int height {0};

        std::cin >> length >> width >> height;

        std::string result = (length <= 20 && width <= 20 && height <= 20) ?
            "good" : "bad";

        std::cout << "Case " << counter++ << ": " << result << "\n";
    }
}
