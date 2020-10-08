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
int color[MAX];

void solveTestCases()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        color[i] = -1;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }

    queue<int> q;
    bool possible = true;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            q.push(i);
            color[i] = 0;
            while (!q.empty())
            {
                int v = q.front();
                q.pop();

                for (int u : adj[v])
                {
                    if (color[u] == -1)
                    {
                        color[u] = color[v] ^ 1;
                        q.push(u);
                    }
                    else
                    {
                        possible &= color[u] != color[v];
                    }
                }
            }
        }
    }

    if (!possible)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << 2 - color[i] << " ";
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