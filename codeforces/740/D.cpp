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
const int MAX = 2e5 + 100;
int n, up[MAX][22];
vector<int> adj[MAX];
int sz[MAX];

// GET SUBTREE SIZE
void getsz(int v, int p)
{
    sz[v] = 1; // every vertex has itself in its subtree
    for (auto u : adj[v])
        if (u != p)
        {
            getsz(u, v);
            sz[v] += sz[u]; // add size of child u to its parent(v)
        }
}

void solveTestCases()
{
    cin >> n;

    for (int u = 1; u < n; u++)
    {
        int v, W;
        cin >> v >> W;
        v--;
        adj[v].pb(u);
    }

    getsz(0, 0);

    for (int i = 0; i < n; i++)
    {
        cout << sz[i] << " ";
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