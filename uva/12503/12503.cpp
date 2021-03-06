// Problem definition: https://uva.onlinejudge.org/external/125/12503.pdf
// Accepted 2019-02-02

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);

    int cases {0};
    cin >> cases;

    while (cases--)
    {
        int n {0};
        cin >> n;

        vector<int> instructions(n);
        string s; 
        for_each(begin(instructions), end(instructions),
            [&](int& i) 
            { 
                cin >> s;
                if (s[0] == 'L') { i = -1; }
                else if (s[0] == 'R') { i = 1; }
                else { cin >> s >> i; i = instructions[i-1]; }
            });
        cout << accumulate(begin(instructions), end(instructions), 0) << "\n";
    }
}
