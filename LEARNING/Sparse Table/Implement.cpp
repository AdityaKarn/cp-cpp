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

int arr[MAX];
int st[MAX][25];
int logX[MAX];
void solveTestCases()
{
    int n;
    cin >> n;

    REP(i, n)
    {
        cin >> arr[i];
    }

    // logXs
    logX[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        logX[i] = logX[i / 2] + 1;
    }

    for (int i = 0; i < n; i++)
    {
        st[i][0] = arr[i];
    }

    for (int j = 1; j <= 25; j++)
    {
        for (int i = 0; i + (1 << j) <= n; i++)
        {
            st[i][j] = min(st[i][j - 1], st[i + (1 << j)][j - 1]);
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        int j = logX[r - l + 1];

        int minimum = min(st[l][j], st[r - (1 << j) + 1][j]);

        cout << minimum << "\n";
    }
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