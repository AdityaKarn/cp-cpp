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
const int MAX = (int)1e4 + 5;

char gr[1001][1001];
bool visited[1001][1001];
int n, m;

void dfs(int i, int j)
{
    visited[i][j] = true;

    if (i + 1 <= n && gr[i + 1][j] == '.' && visited[i + 1][j] == false)
    {
        dfs(i + 1, j);
    }
    if (j + 1 <= m && gr[i][j + 1] == '.' && visited[i][j + 1] == false)
    {
        dfs(i, j + 1);
    }
    if (i - 1 >= 0 && gr[i - 1][j] == '.' && visited[i - 1][j] == false)
    {
        dfs(i - 1, j);
    }
    if (j >= 0 && gr[i][j - 1] == '.' && visited[i][j - 1] == false)
    {
        dfs(i, j - 1);
    }
}

void solveTestCases()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            gr[i][j] = s[j];
            visited[i][j] = false;
        }
    }

    lli cc = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (gr[i][j] == '.' && visited[i][j] == false)
            {
                dfs(i, j);
                cc++;
            }
        }
    }

    cout << cc << "\n";
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