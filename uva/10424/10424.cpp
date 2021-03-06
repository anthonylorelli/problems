// Problem definition: https://uva.onlinejudge.org/external/104/10424.pdf
// Accepted 2019-02-08

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <numeric>
#include <cctype>
#include <iomanip>
#include <cstdio>

std::unordered_map<char,int> valueMap {
    {'a',1},{'b',2},{'c',3},{'d',4},{'e',5},{'f',6},{'g',7},
    {'h',8},{'i',9},{'j',10},{'k',11},{'l',12},{'m',13},{'n',14},
    {'o',15},{'p',16},{'q',17},{'r',18},{'s',19},{'t',20},
    {'u',21},{'v',22},{'w',23},{'x',24},{'y',25},{'z',26},
    {'A',1},{'B',2},{'C',3},{'D',4},{'E',5},{'F',6},{'G',7},
    {'H',8},{'I',9},{'J',10},{'K',11},{'L',12},{'M',13},{'N',14},
    {'O',15},{'P',16},{'Q',17},{'R',18},{'S',19},{'T',20},
    {'U',21},{'V',22},{'W',23},{'X',24},{'Y',25},{'Z',26} };

int Reduce(int n)
{
    int sum {0};

    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

double Calculate(std::string& s)
{
    int total {std::accumulate(s.begin(), s.end(), 0,
        [&] (int n, const char c) { return n + (std::isalpha(c) ? valueMap[c] : 0); })};

    while (total > 9) { total = Reduce(total); }

    return static_cast<double>(total);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::string first, second;

    while (std::getline(std::cin, first))
    {
        std::getline(std::cin, second);
        double numerator {Calculate(first)};
        double denominator {Calculate(second)};
        if (numerator > denominator) { std::swap(numerator, denominator); }
        double ratio {100.0*(numerator/denominator)};
        
        std::printf("%.2f %%\n", ratio);
    }
}
