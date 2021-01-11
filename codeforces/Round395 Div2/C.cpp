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

const int MAX = 1e5 + 5;
struct edge
{
    int x;
    int y;
};

edge e[MAX];

int color[MAX];
int cnt[MAX];

void solveTestCases()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n - 1; i++)
    {
        cin >> e[i].x >> e[i].y;
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> color[i];
    }

    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        if (color[e[i].x] != color[e[i].y])
        {
            sum++;
            cnt[e[i].x]++;
            cnt[e[i].y]++;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (cnt[i] == sum)
        {
            cout << "YES\n";
            cout << i << "\n";
            return;
        }
    }
    cout << "NO\n";
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