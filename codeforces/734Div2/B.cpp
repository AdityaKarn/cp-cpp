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
    int k2, k3, k5, k6;

    cin >> k2 >> k3 >> k5 >> k6;

    int tfs = min(k2, k5);
    tfs = min(tfs, k6);
    // cout << tfs << "\n";
    lli res = (lli)tfs * (lli)256;

    k2 -= tfs;

    int tt = min(k2, k3);

    res += (lli)tt * (lli)32;

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