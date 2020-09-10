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

int dp[101][9];

void solveTestCases()
{
    int m, s;
    cin >> m >> s;

    if (m == 1 && s == 0)
    {
        cout << "0 0";
        return;
    }
    if (s == 0 || s > 9 * m)
    {
        cout << "-1 -1";
        return;
    }

    vector<int> minimum(m + 1, 0);

    int remaining_sum = s - 1;

    for (int i = m; i > 0 && remaining_sum > 0; i--)
    {
        if (remaining_sum >= 9)
        {
            minimum[i] = 9;
            remaining_sum -= 9;
        }
        else
        {
            minimum[i] = remaining_sum;
            remaining_sum = 0;
        }
    }

    minimum[1] = minimum[1] + 1;

    for (int i = 1; i <= m; i++)
    {
        cout << minimum[i];
    }
    cout << " ";

    vector<int> maximum(m + 1, 0);

    remaining_sum = s;

    for (int i = 1; i <= m && remaining_sum > 0; i++)
    {
        if (remaining_sum >= 9)
        {
            maximum[i] = 9;
            remaining_sum -= 9;
        }
        else
        {
            maximum[i] = remaining_sum;
            remaining_sum = 0;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        cout << maximum[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t = 1;

    while (t--)
    {
        solveTestCases();
    }

    return 0;
}