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

void solveTestCases()
{
    lli n, a, b, c;
    cin >> n >> a >> b >> c;

    lli rem = (n % 4);

    if (rem == 0)
    {
        cout << "0\n";
        return;
    }

    rem = 4 - rem;

    lli dp[101];
    dp[0] = 0;
    dp[1] = a;
    dp[2] = min(a + a, b);

    for (int i = 3; i < 100; i++)
    {
        dp[i] = min(dp[i - 1] + a, dp[i - 2] + b);
        dp[i] = min(dp[i], dp[i - 3] + c);
    }

    // for (int i = 0; i < 10; i++)
    // {
    //     cout << dp[i] << " ";
    // }
    lli res = INT_MAX;

    for (int i = rem; i <= 100; i += 4)
    {
        res = min(res, dp[i]);
    }

    cout << res << "\n";
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