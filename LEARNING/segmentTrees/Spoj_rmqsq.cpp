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
const int MAX = (int)1e5 + 5;

int a[MAX], st[4 * MAX];

void buildTree(int v, int sl, int sr)
{
    if (sl == sr)
    {
        st[v] = a[sl];
    }
    else
    {
        int sm = ((sl + sr) / 2);

        buildTree(v * 2, sl, sm);
        buildTree(v * 2 + 1, sm + 1, sr);

        st[v] = min(st[v * 2], st[v * 2 + 1]);
    }
    // trace1(st[v]);
}

int query(int v, int sl, int sr, int l, int r)
{
    if (l > r)
    {
        return INF;
    }
    if (l == sl && r == sr)
    {
        return st[v];
    }

    int sm = (sl + sr) / 2;

    return min(query(v * 2, sl, sm, l, min(r, sm)), query(v * 2 + 1, sm + 1, sr, max(l, sm + 1), r));
}

// void update(int v, int sl, int sr, int pos, int new_value)
// {
//     if (sl == sr)
//     {
//         st[v] = new_value;
//     }
//     else
//     {
//         int sm = (sl + sr) / 2;
//         if (pos <= sm)
//         {
//             update(v * 2, sl, sm, pos, new_value);
//         }
//         else
//         {
//             update(v * 2 + 1, sm + 1, sr, pos, new_value);
//         }
//         st[v] = st[v * 2] + st[v * 2 + 1];
//     }
// }

void solveTestCases()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    buildTree(1, 0, n - 1);

    int q;
    cin >> q;

    // for (int i = 0; i < 4 * n; i++)
    // {
    //     cout << st[i] << " ";
    // }
    // cout << "\n";

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        cout << query(1, 0, n - 1, l, r) << "\n";
    }
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