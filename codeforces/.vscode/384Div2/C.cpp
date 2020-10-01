#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <array>
#define REP(i, n) for (int i = 0; i < n; i++)

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
const int MAX = (int)1e4 + 5;

vector<int> adj[1001];
int govt[1001];
int mx;
bool visited[1001];
bool go;
void dfs(int src, int size)
{
    mx = max(mx, size);
    if (govt[src])
    {
        go = true;
    }
    visited[src] = true;

    for (int i = 0; i < adj[src].size(); i++)
    {
        int to = adj[src][i];

        if (!visited[to])
            dfs(to, size + 1);
    }
}

void solveTestCases()
{
    int n, m, k;
    cin >> n >> m >> k;

    REP(i, n + 1)
    {
        govt[i] = 0;
    }

    for (int i = 0; i < k; i++)
    {
        int u;
        cin >> u;
        govt[u] = 1;
    }

    REP(i, m)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b), adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
    }

    vector<array<int, 3>> cComp;
    for (int i = 1; i <= n; i++)
    {
        go = false;
        mx = 0;
        if (!visited[i])
        {
            dfs(i, 1);
            cComp.push_back({mx, i, go});
        }
    }

    sort(cComp.rbegin(), cComp.rend());

    lli first = 0;

    for (auto cc : cComp)
    {
        // cout << cc[0] << " " << cc[1] << " " << cc[2] << "\n";
        first += (cc[0] * (cc[0] - 1)) / 2;
    }
    first -= m;

    // cout << first;

    lli second = 0;

    int largest = cComp[0][1], largSize = cComp[0][0];
    int totalSize = largSize;

    for (int i = 1; i < cComp.size(); i++)
    {
        if (cComp[i][2] == 0)
        {

            second += largSize * cComp[i][0];
            totalSize += cComp[i][0];
        }
    }

    // if largest was a govt
    if (cComp[0][2])
    {
        lli res = first + second;
        cout << res << "\n";
        return;
    }

    // if largest was not a govt
    int idxLargestGovt = -1;

    for (int i = 1; i <= cComp.size(); i++)
    {
        if (cComp[i][2])
        {
            idxLargestGovt = i;
            break;
        }
    }

    second += totalSize * (lli)1 * cComp[idxLargestGovt][0];

    lli res = first + second;
    cout << res << "\n";
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