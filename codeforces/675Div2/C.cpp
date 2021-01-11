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

lli res = 0;

lli num;

void calc(string s, int x)
{
    for (int i = 0; i < s.size() - x + 1; i++)
    {
        string sub = s.substr(i, x);
        lli m = stol(sub, nullptr, 10);

        trace1(m);
        }
}

void solveTestCases()
{
    string s;
    cin >> s;

    int n;
    n = s.size();

    num = stol(s, nullptr, 10);

    // cout << num;
    for (int i = 1; i <= n; i++)
    {
        calc(s, i);
    }
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