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

using namespace std;

int cats[100002];
vector<int> adj[100002];
bool visited[100002];

int cnt = 0;

void dfs(int src, int m)
{
    cout << src << " " << m << " " << cnt << "\n";
    visited[src] = true;

    if (cats[src] == 1)
    {
        m--;
        if (m < 0)
        {

            return;
        }
    }

    if (adj[src].size() == 0)
    {
        cnt++;
        return;
    }

    for (int child : adj[src])
    {
        if (!visited[child])
            dfs(child, m);
    }
}

void solveTestCases()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> cats[i];
        visited[i] = false;
    }

    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    dfs(1, m);
    cout << cnt << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t = 1;

    while (t--)
    {
        solveTestCases();
    }

    return 0;
}