#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define REP(i, n) for (int i = 1; i <= n; i++)

#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000

using namespace std;

int main()
{
    string exp;
    int t, n, res, checkLimit;
    cin >> t;
    char ch;

    while (t--)
    {
        int a = 0, b = 0;

        cin >> n;
        res = 2 * n;

        if (n % 2 == 0)
            checkLimit = n / 2;
        else
            checkLimit = (n + 1) / 2;

        cin >> exp;

        for (int i = 0; i < 2 * n; i++)
        {
            int block = i / 2;
            ch = exp[i];

            //keeping scores
            if (ch == '1' && n % 2 == 0)
            {
                a++;
            }
            else if (ch == '1' && n % 2 == 1)
            {
                b++;
            }

            //check for possible win
            if (i % 2 == 0 && block >= checkLimit)
            {
                int toWin = n - block + 1;

                if (abs(a - b) >= toWin)
                {
                    res = i;
                }
            }
        }

        cout << res << endl;
    }
}