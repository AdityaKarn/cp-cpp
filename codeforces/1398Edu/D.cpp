#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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

int dp[201][201][201];

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int sr, sg, sb, cur;
    cin >> sr >> sg >> sb;

    vector<int> red, green, blue;
    for (int i = 0; i < sr; i++)
    {
        cin >> cur;
        red.push_back(cur);
    }
    for (int i = 0; i < sg; i++)
    {
        cin >> cur;
        green.push_back(cur);
    }
    for (int i = 0; i < sb; i++)
    {
        cin >> cur;
        blue.push_back(cur);
    }
    sort(red.begin(), red.end(), greater<int>());
    sort(green.begin(), green.end(), greater<int>());
    sort(blue.begin(), blue.end(), greater<int>());

    int res = 0;

    for (int i = 0; i < sr + 1; i++)
    {
        for (int j = 0; j < sg + 1; j++)
        {
            for (int k = 0; k < sb + 1; k++)
            {
                dp[i][j][k] = 0;
            }
        }
    }

    for (int i = 0; i < sr + 1; i++)
    {
        for (int j = 0; j < sg + 1; j++)
        {
            for (int k = 0; k < sb + 1; k++)
            {
                if (i < sr && j < sg)
                {
                    dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + red[i] * green[j]);
                }
                if (j < sg && k < sb)
                {
                    dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k] + green[j] * blue[k]);
                }
                if (i < sr && k < sb)
                {
                    dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + red[i] * blue[k]);
                }
            }
        }
    }

    for (int i = 0; i < sr + 1; i++)
    {
        for (int j = 0; j < sg + 1; j++)
        {
            for (int k = 0; k < sb + 1; k++)
            {
                res = max(res, dp[i][j][k]);
            }
        }
    }
    cout << res << "\n";
    return 0;
}