#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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

vector<int> adj[10001];
bool visited[10001];

bool isCycle(int node, int par)
{
    visited[node] = 1;

    for (int child : adj[node])
    {
        if (visited[child == 0])
        {
            if (isCycle(child, node) == true)
                return true;
        }

        else if (child != par)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;

    REP(i, m)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << isCycle(2, 1);

    return 0;
}