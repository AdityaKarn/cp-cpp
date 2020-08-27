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

using namespace std;

int dp[10004];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;

        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {

            if (i % 2 == 0)
            {
                dp[i] = min(dp[i - 1] + 1, dp[i / 2] + 1);
            }
            else
            {
                dp[i] = dp[i - 1] + 1;
            }
        }

        cout << dp[n] << "\n";
    }
    return 0;
}