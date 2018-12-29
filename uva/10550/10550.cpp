// Problem definition: https://uva.onlinejudge.org/external/105/10550.pdf
// Accepted ?

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int position {0};
    int cA {0};
    int cB {0};
    int cC {0};

    while ((std::cin >> position >> cA >> cB >> cC) &&
        !(position == 0 && cA == 0 && cB == 0 && cC == 0))
    {
        // Turn the dial clockwise two full turns
        // Stop at the first number of the combination
        // Turn the dial counter clockwise one full turn
        // Continue turning until the second number is reached
        // Turn the dial back clockwise until the third number is reached
        // Pull the shank and the lock will open
        int totalDegrees {1080};
        constexpr int scaleFactor {9};
        int ticksMoved {0};

        if (position < cA)
        {
            ticksMoved += cA - position;
        }
        else
        {
            ticksMoved = (40 - position) + cA;
        }

        if (cA > cB)
        {
            ticksMoved += cA - cB;
        }
        else
        {
            ticksMoved = cA + (40 - cB);
        }

        if (cB < cC)
        {
            ticksMoved += cC - cB;
        }
        else
        {
            ticksMoved = (40 - cB) + cC;
        }

        totalDegrees += ticksMoved * scaleFactor;

        std::cout << totalDegrees << "\n";
    }
}
