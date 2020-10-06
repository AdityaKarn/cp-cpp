#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
const int MAX = (int)1e5 + 5;

vector<int> adj[MAX];
int dis[MAX];
bool visited[MAX];
int from[MAX];
void solveTestCases()
{

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
        dis[i] = INT_MAX;
    }

    queue<int> q;
    q.push(1);
    // cout << "heree";

    dis[1] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        visited[cur] = true;
        // cout << "currently at " << cur << "\n";
        if (cur == n)
        {
            break;
        }

        for (int i = 0; i < adj[cur].size(); i++)
        {
            int to = adj[cur][i];
            if (!visited[to])
            {
                visited[to] = 1;
                from[to] = cur;
                q.push(to);
            }
        }
    }

    if (visited[n] == false)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<int> res;

    res.pb(n);
    int y = n;

    while (y != 1)
    {
        y = from[y];
        res.pb(y);
    }
    reverse(res.begin(), res.end());

    cout << res.size() << "\n";
    for (auto v : res)
    {
        cout << v << " ";
    }
}

int main()
{
    IOS;

    solveTestCases();

    return 0;
}