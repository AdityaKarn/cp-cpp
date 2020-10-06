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
const int MAX = (int)1e5 + 5;

int arr[MAX];

void solveTestCases()
{
    int n, m;

    cin >> n >> m;

    vector<vector<int>> dp(n, vector<int>(m + 1, 0));

    int x0;
    cin >> x0;

    if (x0 == 0)
    {
        fill(dp[0].begin(), dp[0].end(), 1);
    }
    else
    {
        dp[0][x0] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;

        if (x == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                for (int k = j - 1; k <= j + 1; k++)
                {
                    if (k >= 1 && k <= m)
                    {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                    }
                }
            }
        }
        else
        {
            for (int k = x - 1; k <= x + 1; k++)
            {
                if (k >= 1 && k <= m)
                {
                    dp[i][x] = (dp[i][x] + dp[i - 1][k]) % mod;
                }
            }
        }
    }
    lli ans = 0;
    for (int j = 1; j <= m; j++)
    {
        ans = (ans + dp[n - 1][j]) % mod;
    }

    cout << ans << "\n";
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