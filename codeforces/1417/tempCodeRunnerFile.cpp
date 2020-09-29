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
int A[300005];
vector<int> idx[300005];
void solveTestCases()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        idx[A[i]].push_back(i + 1);
    }
    vector<int> Res(n + 1, n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (idx[i].empty())
        {
            continue;
        }

        int maxGap = -1;

        for (int j = 0; j < idx[i].size(); j++)
        {
            if (j == 0)
            {
                maxGap = max(maxGap, idx[i][j] - 1);
            }
            if (j == idx[i].size() - 1)
            {
                maxGap = max(maxGap, n - idx[i][j]);
            }
            if (j >= 1)
            {
                maxGap = max(maxGap, idx[i][j] - idx[i][j - 1] - 1);
            }
        }
        // cout << i << ' ' << maxGap << "\n";
        Res[maxGap + 1] = min(Res[maxGap + 1], i);
    }

    int mn = n + 1;
    for (int i = 1; i <= n; i++)
    {
        // cout << Res[i] << " ";
        mn = min(mn, Res[i]);

        if (mn == n + 1)
        {
            cout << "-1 ";
        }
        else
        {
            cout << mn << " ";
        }
    }
    cout << "\n";
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