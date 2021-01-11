#include <bits/stdc++.h>

#define REP(i, n) for (lli i = 0; i < n; i++)
#define trace1(x) cerr << #x << ": " << x << "\n"
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << "\n"
#define trace3(x, y, z) cerr << #x << ":" << x << " | " << #y << ": " << y << " | " << #z << ": " << z << "\n"
#define trace4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << "\n"
#define trace5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << "\n"
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<lli, lli>
#define vi vector<lli>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

lli a[101][101];

void solveTestCases()
{
    lli n, m, k, x, y;

    cin >> n >> m >> k >> x >> y;

    if (n == 1)
    {
        lli tot = k / m;
        lli rem = k % m;

        for (lli i = 1; i <= m; i++)
        {
            a[1][i] += tot;
        }
        for (lli i = 1; i <= rem; i++)
        {
            a[1][i]++;
        }
    }
    else
    {
        lli period = n * m + (n - 2) * m;
        lli tot = k / period;
        lli rem = k % period;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i == 1 || i == n)
                    a[i][j] += tot;
                else
                    a[i][j] += 2 * tot;
            }
        }
        for (int i = 1; i <= n && rem > 0; i++)
        {
            for (int j = 1; j <= m && rem > 0; j++)
            {
                a[i][j]++;
                rem--;
            }
        }
        for (int i = n - 1; i >= 1 && rem > 0; i--)
        {
            for (int j = 1; j <= m && rem > 0; j++)
            {
                a[i][j]++;
                rem--;
            }
        }
    }

    lli mx = 0, mn = INT_MAX;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            mx = max(mx, a[i][j]);
            mn = min(mx, a[i][j]);
        }
    }

    cout << mx << " " << mn << " " << a[x][y] << "\n";
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