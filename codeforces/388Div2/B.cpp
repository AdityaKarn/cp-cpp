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
void solveTestCases()
{
    ii a, b, c;

    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;

    cout << "3\n";

    int x, y;

    x = (a.first + b.first - c.first);
    y = (a.second + b.second - c.second);

    cout << x << " " << y << "\n";

    x = (a.first - b.first + c.first);
    y = (a.second - b.second + c.second);

    cout << x << " " << y << "\n";

    x = (-a.first + b.first + c.first);
    y = (-a.second + b.second + c.second);

    cout << x << " " << y << "\n";
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