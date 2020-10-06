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
    int n;
    cin >> n;

    int target = (n * (n + 1)) / 2;
    if (target % 2 == 1)
    {
        cout << "0\n";
        return;
    }

    target /= 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    dp[0][0] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            dp[i][j] = dp[i - 1][j];
            int left = j - i;

            if (left >= 0)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][left]) % mod;
            }
        }
    }

    cout << dp[n - 1][target] << "\n";
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