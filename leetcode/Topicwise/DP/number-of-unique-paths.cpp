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

int dp[21][21];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, m, n;

    cin >> t;

    while (t--)
    {
        cin >> m >> n;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i - 1 >= 0)
                {

                    dp[i][j] += dp[i - 1][j];
                }
                if (j - 1 >= 0)
                {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }

        cout << dp[m - 1][n - 1] << "\n";
    }

    return 0;
}