#include <iostream>
#include <vector>
#include <algorithm>

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

using namespace std;

char arr[1001][1001];
int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool vis[1001][1001];

bool isValid(int x, int y)
{
    if (x < 0 || y < 0 || x >= n && y >= m)
    {
        return false;
    }
    if (vis[x][y] == true || arr[x][y] == '#')
    {
        return false;
    }
    return true;
}

void dfs(int x, int y)
{
    vis[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        if (isValid(x + dx[i], y + dy[i]))
        {
            dfs(x + dx[i], y + dy[i]);
        }
    }
}

int main()
{

    cin >> n >> m;

    REP(i, n)
    {
        REP(j, m)
        {
            cin >> arr[i][j];
        }
    }

    int cnt = 0;

    REP(i, n)
    {
        REP(j, m)
        {

            if (vis[i][j] == 0 && arr[i][j] == '.')
            {
                cnt++;
                dfs(i, j);
            }
        }
    }

    cout << cnt;

    return 0;
}