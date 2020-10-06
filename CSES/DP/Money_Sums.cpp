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
const int MAX = (int)1e4 + 5;
void solveTestCases()
{
    int n;
    cin >> n;
    int maxSum = n * 1000;

    vector<int> coins(n);

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(maxSum + 1, false));

    dp[0][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= maxSum; j++)
        {
            dp[i][j] = dp[i - 1][j];

            int left = j - coins[i - 1];

            if (left >= 0 && dp[i - 1][left])
            {
                dp[i][j] = true;
            }
        }
    }

    vector<int> pos;

    for (int j = 1; j <= maxSum; j++)
    {
        if (dp[n][j])
        {
            pos.push_back(j);
        }
    }

    cout << pos.size() << "\n";

    for (auto x : pos)
    {
        cout << x << " ";
    }
    cout << "\n";
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