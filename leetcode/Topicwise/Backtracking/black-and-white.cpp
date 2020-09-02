#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int m, n;

        cin >> m >> n;

        lli res = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                lli toAdd = (m * n) - 1;
                if (i + 2 < m && j + 1 < n)
                {
                    toAdd -= 1;
                }
                if (i + 2 < m && j - 1 >= 0)
                {

                    toAdd -= 1;
                }
                if (i + 1 < m && j + 2 < n)
                {

                    toAdd -= 1;
                }
                if (i + 1 < m && j - 2 >= 0)
                {

                    toAdd -= 1;
                }
                if (i - 2 >= 0 && j - 1 >= 0)
                {
                    toAdd -= 1;
                }
                if (i - 2 >= 0 && j + 1 < n)
                {

                    toAdd -= 1;
                }
                if (i - 1 >= 0 && j + 2 < n)
                {

                    toAdd -= 1;
                }
                if (i - 1 >= 0 && j - 2 >= 0)
                {

                    toAdd -= 1;
                }

                res += toAdd;
            }
        }

        cout << res << "\n";
    }
    return 0;
}