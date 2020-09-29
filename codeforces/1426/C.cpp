#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
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

int n;

void solveTestCases()
{
    cin >> n;
    lli res = 1e9;
    for (int i = 1; i * i <= n; i++)
    {
        res = min(res, (lli)(i - 1 + (((n - i) + i - 1) / i)));
    }

    cout << res << "\n";
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