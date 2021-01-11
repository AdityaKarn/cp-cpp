#include <bits/stdc++.h>

#define REP(i, n) for (int i = 1; i <= n; i++)
#define trace1(x) cerr << #x << ": " << x << "\n"
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << "\n"
#define trace3(x, y, z) cerr << #x << ":" << x << " | " << #y << ": " << y << " | " << #z << ": " << z << "\n"
#define trace4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << "\n"
#define trace5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << "\n"
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

const int MAX = (int)1e2 + 5;

lli median(lli a, lli b, lli c, lli d)
{
    vector<int> v(4);

    v[0] = a, v[1] = b, v[2] = c, v[3] = d;

    sort(v.begin(), v.end());

    return (v[1] + v[2]) / 2;
}

lli arr[MAX][MAX];
void solveTestCases()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    lli res = 0;
    int iter_x = n / 2;
    bool ex_x = false;
    if (n % 2)
    {
        ex_x = true;
    }

    int iter_y = m / 2;
    bool ex_y = false;
    if (m % 2)
    {
        ex_y = true;
    }
    // trace2(iter_x, iter_y);
    for (int i = 0; i < iter_x; i++)
    {
        for (int j = 0; j < iter_y; j++)
        {
            // trace2(i, j);
            lli a = arr[i][j], b = arr[n - 1 - i][j], c = arr[n - 1 - i][m - 1 - j], d = arr[i][m - 1 - j];

            lli mean = median(a, b, c, d);
            res += abs(mean - a) + abs(mean - b) + abs(mean - c) + abs(mean - d);
        }
    }

    if (ex_x)
    {
        for (int j = 0; j < iter_y; j++)
        {
            // trace1(j);
            lli a = arr[n / 2][j], b = arr[n / 2][m - 1 - j];
            lli mean = (a + b) / 2;
            res += abs(mean - a) + abs(mean - b);
        }
    }

    if (ex_y)
    {
        for (int i = 0; i < iter_x; i++)
        {
            // trace1(i);
            lli a = arr[i][m / 2], b = arr[n - 1 - i][m / 2];
            lli mean = (a + b) / 2;
            res += abs(mean - a) + abs(mean - b);
        }
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