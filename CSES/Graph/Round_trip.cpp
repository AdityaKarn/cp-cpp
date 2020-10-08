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
const int MAX = (int)1e5 + 5;
vector<int> adj[MAX];
bool visited[MAX];
int from[MAX];
pair<int, int> edge;
void dfs(int v, int p)
{
    visited[v] = true;
    from[v] = p;

    for (auto u : adj[v])
    {
        if (visited[u] == false)
        {
            dfs(u, v);
        }
        else if (visited[u] == true && u != p)
        {
            edge = make_pair(u, v);
        }
    }
}

void solveTestCases()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].pb(b), adj[b].pb(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i, -1);
        }
    }

    // cout << edge.first << " " << edge.second;

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << from[i] << " ";
    // }

    if (edge.first == 0 && edge.second == 0)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<int> res;
    int s = edge.first;

    while (s != edge.second)
    {
        res.pb(s);
        s = from[s];
    }

    res.pb(edge.second);
    res.pb(edge.first);

    cout << res.size() << "\n";

    for (auto t : res)
    {
        cout << t << " ";
    }
    cout << "\n";
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