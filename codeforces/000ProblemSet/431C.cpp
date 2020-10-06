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

int dp[101][2];
void solveTestCases()
{
    int n, k, d;

    cin >> n >> k >> d;

    dp[0][0] = 1;
    dp[0][1] = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i][1] = 0;

        for (int j = 0; j <= k; j++)
        {
            if (i < j)
                break;

            if (j < d)
            {
                dp[i][0] = (dp[i][0] + dp[i - j][0]) % mod;
                dp[i][1] = (dp[i][1] + dp[i - j][1]) % mod;
            }
            else
            {
                dp[i][1] = (dp[i][1] + dp[i - j][0]) % mod;
                dp[i][1] = (dp[i][1] + dp[i - j][1]) % mod;
            }
        }
    }

    cout << dp[n][1] << "\n";
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