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
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
const int MAX = (int)1e6 + 5;

lli dp[MAX];
void init()
{
    for (int i = 0; i < MAX; i++)
    {
        dp[i] = 0;
    }
}
void solveTestCases()
{
    int n;
    cin >> n;

    dp[1] = 1, dp[2] = 1, dp[3] = 1, dp[4] = 1, dp[5] = 1, dp[6] = 1;

    for (int i = 2; i <= n; i++)
    {
        if (i >= 2)
        {
            dp[i] += dp[i - 1] % mod;
        }
        if (i >= 3)
        {
            dp[i] += dp[i - 2] % mod;
        }
        if (i >= 4)
        {
            dp[i] += dp[i - 3] % mod;
        }
        if (i >= 5)
        {
            dp[i] += dp[i - 4] % mod;
        }
        if (i >= 6)
        {
            dp[i] += dp[i - 5] % mod;
        }
        if (i >= 7)
        {
            dp[i] += dp[i - 6] % mod;
        }
    }

    cout << dp[n] % mod << "\n";
}

int main()
{
    init();
    IOS;
    int t;
    t = 1;

    while (t--)
    {
        solveTestCases();
    }

    return 0;
}