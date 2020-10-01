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

int dp[MAX];
int Coins[101];

void solveTestCases()
{
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> Coins[i];
    }

    for (int i = 0; i <= x; i++)
    {
        dp[i] = INT_MAX;
    }

    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - Coins[j] == 0)
            {
                dp[i] = 1;
            }

            if (i - Coins[j] >= 0 && dp[i - Coins[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - Coins[j]] + 1);
            }
        }
    }
    if (dp[x] == INT_MAX)
    {
        cout << "-1\n";
    }
    else
        cout << dp[x] << "\n";
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