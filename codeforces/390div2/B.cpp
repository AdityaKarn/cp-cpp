#include <bits/stdc++.h>

#define REP(i, n) for (int i = 1; i <= n; i++)
#define trace1(x) cerr << #x << ": " << x << "\n"
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << "\n"
#define trace3(x, y, z) cerr << #x << ":" << x << " | " << #y << ": " << y << " | " << #z << ": " << z << "\n"
#define trace4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << "\n"
#define trace5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << "\n"
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
int grid[5][5];

bool checkHori(int i, int j)
{
    if (j <= 1)
    {
        if (grid[i][j] + grid[i][j + 1] + grid[i][j + 2] == -1)
        {
            return true;
        }
        // trace3(grid[i][j], grid[i][j + 1], grid[i][j + 2]);
    }

    if (j > 1)
    {
        if (grid[i][j] + grid[i][j - 1] + grid[i][j - 2] == -1)
        {
            return true;
        }
        // trace3(grid[i][j], grid[i][j - 1], grid[i][j - 2]);
    }

    return false;
}

bool checkVerti(int i, int j)
{
    if (i <= 1)
    {
        if (grid[i][j] + grid[i + 1][j] + grid[i + 2][j] == -1)
        {
            return true;
        }
        // trace3(grid[i][j], grid[i + 1][j], grid[i + 2][j]);
    }

    if (i > 1)
    {
        if (grid[i][j] + grid[i - 1][j] + grid[i - 2][j] == -1)
        {
            return true;
        }
        // trace3(grid[i][j], grid[i - 1][j], grid[i - 2][j]);
    }

    return false;
}

bool checkDiagonal(int i, int j)
{
    if (i <= 1 && j <= 1)
    {
        if (grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] == -1)
        {
            return true;
        }
    }
    if (i > 1 && j > 1)
    {
        if (grid[i][j] + grid[i - 1][j - 1] + grid[i - 2][j - 2] == -1)
        {
            return true;
        }
    }

    return false;
}

bool checkDiagonal2(int i, int j)
{
    if (i > 1 && j <= 1)
    {
        if (grid[i][j] + grid[i - 1][j + 1] + grid[i - 2][j + 2] == -1)
        {
            return true;
        }
    }
    if (i <= 1 && j > 1)
    {
        if (grid[i][j] + grid[i + 1][j - 1] + grid[i + 2][j - 2] == -1)
        {
            return true;
        }
        // trace3(grid[i][j], grid[i + 1][j - 1], grid[i + 2][j - 2]);
    }

    return false;
}

void solveTestCases()
{
    for (int i = 0; i < 4; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < 4; j++)
        {
            if (s[j] == '.')
            {
                grid[i][j] = -1;
            }
            else if (s[j] == 'x')
            {
                grid[i][j] = 0;
            }
            else if (s[j] == 'o')
            {
                grid[i][j] = 1;
            }
        }
    }

    bool possible = false;

    for (int i = 0; i < 4; i++)
    {
        if (possible)
        {
            break;
        }
        for (int j = 0; j < 4; j++)
        {
            // cout << grid[i][j];

            if (grid[i][j] == 0)
            {
                bool chk = checkHori(i, j);
                if (chk == true)
                {
                    possible = true;
                    break;
                }

                chk = checkVerti(i, j);
                if (chk == true)
                {
                    possible = true;
                    break;
                }
                chk = checkDiagonal(i, j);
                if (chk == true)
                {
                    possible = true;
                    break;
                }
                chk = checkDiagonal2(i, j);
                if (chk == true)
                {
                    possible = true;
                    break;
                }
            }
        }
        // cout << "\n";
    }

    if (possible)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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