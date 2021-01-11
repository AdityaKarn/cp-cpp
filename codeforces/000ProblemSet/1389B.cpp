#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
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
const int MAX = (int)1e5 + 5;

int a[MAX];

void solveTestCases()
{
    int n, k, z;
    cin >> n >> k >> z;

    REP(i, n)
    {
        cin >> a[i];
    }

    int mx = 0, s = 0;
    int ans = 0;
    for (int t = 0; t <= z; t++)
    {
        int pos = k - 2 * t;

        if (pos < 0)
            continue;

        mx = 0, s = 0;
        for (int i = 0; i <= pos; i++)
        {
            if (i < n - 1)
            {
                mx = max(mx, a[i] + a[i + 1]);
            }

            s += a[i];
        }

        ans = max(ans, s + mx * t);
    }

    cout << ans << "\n";
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