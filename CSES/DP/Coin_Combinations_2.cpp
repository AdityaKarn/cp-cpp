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

int dp[101][MAX];
int Coins[102];

void solveTestCases()
{
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> Coins[i];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;

            int left = j - Coins[i - 1];

            if (j - Coins[i - 1] >= 0)
            {
                dp[i][j] = (dp[i][j] + dp[i][left]) % mod;
            }
        }
    }

    cout << dp[n][x] << "\n";
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