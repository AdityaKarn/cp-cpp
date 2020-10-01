#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)

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
const int MAX = (int)1e3 + 5;
int n, x;
int h[MAX], s[MAX];

void solveTestCases()
{
    cin >> n >> x;
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j];

            int Moneyleft = j - h[i - 1];

            if (Moneyleft >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][Moneyleft] + s[i - 1]);
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