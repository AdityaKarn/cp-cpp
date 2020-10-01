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

void solveTestCases()
{
    int x;
    cin >> x;
    dp[0] = 0;
    for (int i = 1; i < 10; i++)
    {
        dp[i] = 1;
    }

    for (int i = 10; i <= x; i++)
    {
        dp[i] = INT_MAX;
    }

    for (int i = 10; i <= x; i++)
    {
        int temp = i;

        while (temp)
        {
            int unit = temp % 10;
            if (unit != 0)
                dp[i] = min(dp[i], dp[i - unit] + 1);
            temp /= 10;
        }
    }

    // for (int i = 10; i <= x; i++)
    // {
    //     cout << dp[i] << " ";
    // }

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