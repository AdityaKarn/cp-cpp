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

void solveTestCases()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    vector<int> pos[N + 1];
    for (int i = 0; i < N; ++i)
    {
        pos[A[i]].push_back(i + 1);
    }

    vector<int> forsize(N + 1, N + 1);
    for (int i = 1; i <= N; ++i)
    {
        int mxgap = -1;
        if (pos[i].empty())
        {
            continue;
        }
        for (int j = 0; j < pos[i].size(); ++j)
        {
            if (j == 0)
            {
                mxgap = max(mxgap, pos[i][j] - 1);
            }
            if (j == pos[i].size() - 1)
            {
                mxgap = max(mxgap, N - pos[i][j]);
            }
            if (j - 1 >= 0)
            {
                mxgap = max(mxgap, pos[i][j] - pos[i][j - 1] - 1);
            }
        }
        forsize[mxgap + 1] = min(forsize[mxgap + 1], i);
    }

    int mn = N + 1;
    for (int len = 1; len <= N; ++len)
    {
        mn = min(mn, forsize[len]);
        if (mn == N + 1)
            cout << -1 << " ";
        else
            cout << mn << " ";
    }
    cout << '\n';
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