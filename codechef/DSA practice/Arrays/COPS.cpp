#include <iostream>
#include <vector>
#include <algorithm>

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

int safe[102];

int main()
{
    int t, m, x, y, range, cop;
    cin >> t;

    while (t--)
    {
        cin >> m >> x >> y;

        range = x * y;

        for (int i = 1; i <= 100; i++)
        {
            safe[i] = 0;
        }

        for (int i = 0; i < m; i++)
        {
            cin >> cop;
            int minCoprange, maxCoprange;

            if (cop - range >= 1)
            {
                minCoprange = cop - range;
            }
            else
            {
                minCoprange = 1;
            }

            if (cop + range <= 100)
            {
                maxCoprange = cop + range;
            }
            else
            {
                maxCoprange = 100;
            }

            for (int i = cop; i >= minCoprange; i--)
            {
                safe[i] = 1;
            }

            for (int i = cop; i <= maxCoprange; i++)
            {
                safe[i] = 1;
            }
        }
        int res = 0;
        for (int i = 1; i <= 100; i++)
        {
            if (safe[i] == 0)
            {
                res++;
            }
        }

        cout << res << endl;
    }
}