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
const int MAX = (int)1e3 + 5;
int dp[MAX][MAX];
int path[MAX][MAX];
void solveTestCases()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == '.')
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = -1;
            }
            path[i][j] = 0;
        }
    }

    bool up = false;
    for (int i = n - 1; i >= 0; i--)
    {
        if (up == false && dp[i][n - 1] == 0)
        {
            path[i][n - 1] = 1;
        }
        else if (up == false && dp[i][n - 1] == -1)
        {
            path[i][n - 1] = 0;
            up = true;
        }
        else if (up == true)
        {
            path[i][n - 1] = 0;
        }
    }

    bool left = false;
    for (int i = n - 1; i >= 0; i--)
    {

        if (left == false && dp[n - 1][i] == 0)
        {
            path[n - 1][i] = 1;
        }
        else if (left == false && dp[n - 1][i] == -1)
        {
            path[n - 1][i] = 0;
            left = true;
        }
        else if (left == true)
        {
            path[n - 1][i] = 0;
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            if (dp[i][j] == -1)
            {
                path[i][j] = 0;
            }
            else
            {
                path[i][j] = (path[i][j] + path[i][j + 1]) % mod;
                path[i][j] = (path[i][j] + path[i + 1][j]) % mod;
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << path[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << path[0][0] << "\n";
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