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
vector<int> adj[300005];

int visited[300005];
int maxdist = 0, farthest;
void dfs(int src, int dist)
{
    visited[src] = 1;

    if (dist > maxdist)
    {
        maxdist = dist;
        farthest = src;
    }
    for (int i = 0; i < adj[src].size(); i++)
    {
        if (visited[adj[src][i]] != 1)
            dfs(adj[src][i], dist + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    maxdist = 0;

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    dfs(farthest, 0);

    cout << 3 * maxdist;

    return 0;
}