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
    string s;
    cin >> s;

    int n = s.size();
    int res = 0;

    vector<ii> contiB;
    vector<bool> uy(n, true);

    bool isB = false;
    int sz = 0;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i] == 'B' && isB)
        {
            sz++;
        }
        if (s[i] == 'B' && !isB)
        {
            sz++;
            isB = true;
        }
        if (s[i] == 'A' && isB)
        {
            contiB.pb({i, sz});
            sz = 0;
            isB = false;
        }
    }

    if (isB)
    {
        contiB.pb({i, sz});
    }
    // cout << "here\n";
    for (auto x : contiB)
    {
        // cout << x.first << " " << x.second << "\n";
        int j = x.first - 1;
        int k = 2 * x.second;

        while (k)
        {
            if (j < 0)
            {
                break;
            }
            uy[j] = false;
            j--;
            k--;
        }
    }

    if (!contiB.empty())
    {
        int firs = contiB[0].first;
        int secon = contiB[0].second;

        if (firs == secon)
        {
            if (secon % 2)
            {
                uy[0] = true;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        // cout << uy[i];
        if (uy[i] == true)
        {
            res++;
        }
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