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
lli p[5001];
lli dp[5001][5001];
lli prefixSum[5001];

void solveTestCases()
{
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    prefixSum[0] = 0;

    for (lli i = 1; i <= n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + p[i];
    }

    for (lli i = 0; i <= n; i++)
    {
        for (lli j = 0; j <= k; j++)
        {
            dp[i][j] = (-1 * INF);
        }
    }
    for (lli i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (lli i = 0; i <= n; i++)
    {
        for (lli j = 1; j <= k; j++)
        {
            if (i >= m)
                dp[i][j] = max(dp[i - 1][j], dp[i - m][j - 1] + prefixSum[i] - prefixSum[i - m]);
        }
    }

    cout << dp[n][k] << "\n";
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