#include <bits/stdc++.h>
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
const int MAX = (int)1e4 + 5;
vector<int> root, siz;

void DSU(int n)
{
    root.resize(n);
    siz.resize(n, 1);

    iota(root.begin(), root.end(), 0);
}

int Find(int a)
{
    if (root[a] == a)
    {
        return a;
    }

    return root[a] = Find(root[a]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a == b)
    {
        return;
    }

    if (siz[a] < siz[b])
    {
        swap(a, b);
    }

    siz[a] += siz[b];
    root[b] = a;
}

void solveTestCases()
{
    int n, m, k;
    cin >> n >> m >> k;

    DSU(n);
    vector<int> IsGovt(n);

    for (int i = 0; i < k; i++)
    {
        int city;
        cin >> city;

        IsGovt[city - 1] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        u--, v--;
        Union(u, v);
    }

    auto nC2 = [](int x) {
        return (lli)x * (x - 1) / 2;
    };

    int mx = -1, rest = n;
    lli ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!IsGovt[i])
        {
            continue;
        }

        ans += nC2(siz[Find(i)]);
        rest -= siz[Find(i)];

        if (siz[Find(i)] > mx)
        {
            mx = siz[Find(i)];
        }
    }

    ans -= nC2(mx);
    ans += nC2(mx + rest);

    cout << ans - m << "\n";
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