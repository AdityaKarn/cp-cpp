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
    int n;
    cin >> n;
    vector<lli> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    lli res = a[n - 1] * a[n - 2] * a[n - 3] * a[n - 4] * a[n - 5];

    res = max(res, a[n - 1] * a[n - 2] * a[n - 3] * a[0] * a[1]);

    res = max(res, a[n - 1] * a[3] * a[2] * a[1] * a[0]);

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