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

int a[2001];
vector<int> graph[2001];
bool visited[2001];
vector<int> parents;
int maxDepth = 0;

void dfs(int src, int depth)
{
    maxDepth = max(maxDepth, depth);
    visited[src] = true;

    for (int i = 0; i < graph[src].size(); i++)
    {
        if (!visited[graph[src][i]])
        {
            dfs(graph[src][i], depth + 1);
        }
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

    for (int i = 1; i <= n; i++)
    {
        if (a[i] != -1)
        {
            graph[a[i]].push_back(i);
        }
        else
        {
            parents.push_back(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (auto root : parents)
    {
        int src = root;
        dfs(src, 1);
    }

    cout << maxDepth << "\n";
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