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

vector<int> tree[200001];
bool visited[200001];
int color[200001];

vector<int> white, black;

// 0 is white . 1 is black
int dfs(int v, int parclr, int Cc)
{
    // cout << "CURRENT IN : " << v << " parClr > " << parclr << " Cc" << Cc << "\n";
    int res = 1;
    if (color[v] == parclr)
    {
        visited[v] = true;
    }
    else
    {
        return 0;
    }

    for (int i = 0; i < tree[v].size(); i++)
    {
        if (!visited[tree[v][i]])
        {
            res = max(res, dfs(tree[v][i], color[v], Cc + 1));
        }
    }
    return max(res, Cc);
}

void solveTestCases()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> color[i];
        visited[i] = false;
    }

    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b), tree[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (color[i] == 0)
            {
                int cnt = dfs(i, color[i], 1);
                white.push_back(cnt);
            }
            else
            {
                int cnt = dfs(i, color[i], 1);
                black.push_back(cnt);
            }
        }
    }

    // for (auto w : white)
    // {
    //     cout << "white  >" << w << "\n";
    // }
    // for (auto b : black)
    // {
    //     cout << "black >" << b << "\n";
    // }

    if (white.empty())
    {
        cout << "0\n";
        return;
    }
    if (black.empty())
    {
        cout << "0\n";
        return;
    }

    int res = min(white.size(), black.size());
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