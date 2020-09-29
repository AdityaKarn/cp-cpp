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
int a[200005];
vector<int> tree[200005];

lli sub_sum[200005], max_sub_sum[200005];

void init(int src, int p)
{
    sub_sum[src] = a[src];
    max_sub_sum[src] = INT_MIN;

    for (int i = 0; i < tree[src].size(); i++)
    {
        int to = tree[src][i];

        if (to == p)
        {
            continue;
        }

        init(to, src);

        sub_sum[src] += sub_sum[to];
        max_sub_sum[src] = max(max_sub_sum[src], max_sub_sum[to]);
    }
    max_sub_sum[src] = max(max_sub_sum[src], sub_sum[src]);
}

lli ans = INT_MIN;

void dfs(int v, int p, lli out)
{
    if (out != INT_MIN)
    {
        ans = max(ans, sub_sum[v] + out);
    }

    vector<pair<lli, int>> miniset;

    for (int i = 0; i < tree[v].size(); i++)
    {
        int to = tree[v][i];

        if (to == p)
        {
            continue;
        }

        miniset.pb(make_pair(max_sub_sum[to], to));

        sort(miniset.rbegin(), miniset.rend());

        if (miniset.size() == 3)
        {
            miniset.pop_back();
        }
    }

    miniset.push_back(make_pair(INT_MIN, -1));

    for (int i = 0; i < tree[v].size(); i++)
    {
        int to = tree[v][i];

        if (to == p)
        {
            continue;
        }

        lli cur = miniset[0].second == to ? miniset[1].first : miniset[0].first;

        dfs(to, v, max(cur, out));
    }
}

void solveTestCases()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n - 1; i++)
    {
        int p, q;
        cin >> p >> q;

        tree[p].pb(q), tree[q].pb(p);
    }

    init(1, -1);
    // cout << sub_sum[3] << " " << max_sub_sum[3];

    dfs(1, -1, INT_MIN);

    if (ans == INT_MIN)
    {
        cout << "Impossible\n";
    }
    else
    {
        cout << ans << "\n";
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