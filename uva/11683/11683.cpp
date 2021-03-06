// Problem definition: https://uva.onlinejudge.org/external/116/11683.pdf
// Accepted 2019-02-13

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int height {0};
    int length {0};

    while (std::cin >> height >> length && !(height == 0 && length == 0))
    {
        int previous {height};
        int count {0};
        for (int i {0}; i < length; ++i)
        {
            int n {0};
            std::cin >> n;

            if (n != height && n < previous)
            {
                count += previous - n;
            }

            previous = n;
        }

        std::cout << count << "\n";
    }
}
