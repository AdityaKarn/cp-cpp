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
const int MAX = 2e+6;

lli a[MAX], b[MAX], c[MAX], d[MAX];
lli n, m, k;
lli x, s;

lli bestMatchForSecondType(lli MoneyLeft)
{
    int l = 0, r = k;
    int m = (l + r + 1) / 2;

    while (l < r)
    {
        m = (l + r + 1) / 2;

        if (d[m] <= MoneyLeft)
        {
            l = m;
        }
        else
        {
            r = m - 1;
        }
    }
    return c[l];
}

void solveTestCases()
{
    cin >> n >> m >> k;

    cin >> x >> s;

    a[0] = x;
    b[0] = 0;
    c[0] = 0;
    d[0] = 0;

    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }

    for (int i = 1; i <= k; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> d[i];
    }

    lli res = n * x;

    for (int i = 0; i <= m; i++)
    {
        lli MoneyLeft = s - b[i];
        if (MoneyLeft < 0)
        {
            continue;
        }
        else
        {
            res = min(res, a[i] * (n - bestMatchForSecondType(MoneyLeft)));
        }
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