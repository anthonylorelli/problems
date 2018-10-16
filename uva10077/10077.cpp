// Problem definition:
// https://uva.onlinejudge.org/external/100/10077.pdf

#include <iostream>
#include <tuple>

typedef std::pair<int, int> fraction;

class SternBrocot
{
public:
    SternBrocot(const int targetNumerator, const int targetDenominator) :
        m_targetNumerator {targetNumerator}, m_targetDenominator {targetDenominator} {}

    void PrintPath() { PrintPath(m_left, m_identity, m_right); }

private:
    void PrintPath(const fraction& left, const fraction& current, const fraction& right)
    {
        if (current.first == m_targetNumerator && current.second == m_targetDenominator) 
        { 
            std::cout << "\n";
            return; 
        }

        if (m_targetNumerator * current.second > current.first * m_targetDenominator)
        {
            std::cout << "R";
            PrintPath(current, std::make_pair(current.first + right.first, current.second + right.second), right);
        }
        else
        {
            std::cout << "L";
            PrintPath(left, std::make_pair(current.first + left.first, current.second + left.second), current);
        }
    }

    const int m_targetNumerator;
    const int m_targetDenominator;

    const fraction m_left { std::make_pair(0, 1) };
    const fraction m_identity { std::make_pair(1, 1) };
    const fraction m_right { std::make_pair(1, 0) };
};

int main()
{
    std::ios_base::sync_with_stdio(false);

    int numerator {0};
    int denominator {0};

    while (std::cin >> numerator && std::cin >> denominator && 
        (numerator != 1 || denominator != 1))
    {
        SternBrocot sb {numerator, denominator};
        sb.PrintPath();
    }
}