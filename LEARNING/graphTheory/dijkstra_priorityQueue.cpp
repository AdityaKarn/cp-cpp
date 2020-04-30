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

vector<pair<int, int>> adj[10001];

int main()
{
    int n, m, a, b, w;
    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n + 1, INF);

    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty())
    {
        int curr = pq.top().second;
        int curr_d = pq.top().first;
        pq.pop();

        for (pair<int, int> edge : adj[curr])
        {
            if (curr_d + edge.second < dist[edge.first])
            {
                dist[edge.first] = curr_d + edge.second;
                pq.push({dist[edge.first], edge.first});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
}
