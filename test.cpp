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
const int MAX = (int)1e5 + 5;

void solveTestCases()
{
    lli n;
    cin >> n;

    vector<lli> PreCalc(n + 1);

    for (lli i = 1; i <= n; i++)
    {
        PreCalc[i] = (lli)((i * (i + 1)) / 2);
    }

    bool isPossible = false;
    for (lli i = 1; i <= n; i++)
    {
        lli firstPart = (i * (i + 1)) / 2;

        lli findN = n - firstPart;
        vector<lli>::iterator toFind;
        toFind = lower_bound(PreCalc.begin(), PreCalc.end(), findN);

        int REM = toFind - PreCalc.begin();
        // trace2(firstPart, PreCalc[REM]);

        if (PreCalc[REM] + firstPart == n)
        {
            // cout << firstPart << " " << PreCalc[REM];
            isPossible = true;
            break;
        }
    }

    if (isPossible)
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