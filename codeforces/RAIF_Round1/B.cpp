#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
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
void solveTestCases()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    lli res = 0;
    lli bothsize = 0;
    lli allconti = true, allanti = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '>')
        {
            allanti = false;
        }
        if (s[i] == '<')
        {
            allconti = false;
        }
        if (s[i] == '-')
        {
            bothsize++;
        }
        else
        {
            if (bothsize)
            {
                res += bothsize + 1;
                // trace1(res);
                bothsize = 0;
            }
        }
    }
    if (bothsize)
    {
        res += bothsize + 1;
    }

    if (s[0] == '-' && s[n - 1] == '-')
    {
        res--;
    }

    if (allanti)
    {
        cout << n << "\n";
        return;
    }
    if (allconti)
    {
        cout << n << "\n";
        return;
    }

    cout << res << "\n";
}

int main()
{
    IOS;
    int t;
    cin >> t;

    while (t--)
    {
        solveTestCases();
    }

    return 0;
}