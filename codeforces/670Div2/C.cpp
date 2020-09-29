#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <functional>
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

vector<vector<int>> graph;
int tempU, tempV;
pair<int, int> p;

vector<int> Centroid(vector<vector<int>> &g)
{
    int n = g.size();
    vector<int> centroid;
    vector<int> sz(n);
    function<void(int, int)> dfs = [&](int u, int prev) {
        sz[u] = 1;
        bool is_centroid = true;
        for (auto v : g[u])
            if (v != prev)
            {
                dfs(v, u);
                sz[u] += sz[v];
                if (sz[v] > n / 2)
                    is_centroid = false;
            }
        if (n - sz[u] > n / 2)
            is_centroid = false;
        if (is_centroid)
            centroid.push_back(u);
    };
    dfs(0, -1);
    return centroid;
}

void dfs2(int u, int par)
{
    int leaf = 1;

    for (auto &it : graph[u])
    {
        if (it == par || it == tempV)
        {
            continue;
        }
        leaf = 0;
        dfs2(it, u);
    }

    if (leaf)
        p = {u, par};
}

void solveTestCases()
{
    int n;
    cin >> n;

    graph = vector<vector<int>>(n);

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        tempU = u, tempV = v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> v = Centroid(graph);

    // cout << v.size();

    if (v.size() == 1)
    {
        cout << tempU + 1 << " " << tempV + 1 << "\n";
        cout << tempU + 1 << " " << tempV + 1 << "\n";
    }
    else
    {
        tempU = v[0], tempV = v[1];
        dfs2(tempU, tempU);

        cout << p.first + 1 << " " << p.second + 1 << "\n";
        cout << p.first + 1 << " " << tempV + 1 << "\n";
    }
}

int main()
{
    // IOS;
    int t;
    cin >> t;

    while (t--)
    {
        solveTestCases();
    }

    return 0;
}