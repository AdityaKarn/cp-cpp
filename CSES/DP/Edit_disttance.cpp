#include <bits/stdc++.h>
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
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
const int MAX = (int)1e4 + 5;
void solveTestCases()
{

    string initial, final;
    cin >> initial >> final;

    int n = initial.size(), m = final.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));

    dp[0][0] = 0;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            }
            if (j)
            {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
            if (i && j)
            {
                if (initial[i - 1] == final[j - 1])
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }
                else
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << dp[n][m] << "\n";
}

int main()
{
    IOS;
    int t;
    t = 1;

    while (t--)
    {
        solveTestCases();
    }

    return 0;
}