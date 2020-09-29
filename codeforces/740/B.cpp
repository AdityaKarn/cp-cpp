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
int a[102];
int p[102];
void solveTestCases()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    p[0] = 0;
    p[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        p[i] = p[i - 1] + a[i];
    }

    lli res = 0;
    while (m--)
    {
        int l, r;
        cin >> l >> r;

        int sum = p[r] - p[l - 1];

        // cout << sum << "\n";

        res += max(sum, 0);
    }

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