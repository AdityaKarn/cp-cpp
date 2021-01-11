#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define trace1(x) cerr << #x << ": " << x << "\n"
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << "\n"
#define trace3(x, y, z) cerr << #x << ":" << x << " | " << #y << ": " << y << " | " << #z << ": " << z << "\n"
#define trace4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << "\n"
#define trace5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << "\n"
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

int a[MAX];
int dp[MAX][3];

void solveTestCases()
{
    int n;
    cin >> n;

    REP(i, n)
    {
        cin >> a[i];
        dp[i][0] = 0;
        dp[i][1] = 0;
        dp[i][2] = 0;
    }
    dp[n][0] = 0;
    dp[n][1] = 0;
    dp[n][2] = 0;

    REP(i, n)
    {
        dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + (i & 1 ? 0 : a[i]));
        if (i + 2 <= n)
            dp[i + 2][1] = max(dp[i + 2][1], max(dp[i][0], dp[i][0]) + (i & 1) ? a[i] : a[i + 1]);
        dp[i + 1][2] = max(dp[i + 1][2], max({dp[i][0], dp[i][1], dp[i][2]}) + (i & 1) ? 0 : a[i]);
    }

    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << "\n";
}

int main()
{
    IOS;
    int t;
    cin >> t;

    while (t--)
    {
        solveTestCases();
    }

    return 0;
}