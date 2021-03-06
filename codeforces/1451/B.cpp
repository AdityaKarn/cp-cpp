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
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;
    // cout << s;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;

        char left = s[l], right = s[r];

        bool pos = false;

        for (int i = l - 1; i >= 0; i--)
        {
            // trace2(s[i], left);
            if (s[i] == left)
            {
                pos = true;
                break;
            }
        }

        for (int i = r + 1; i < n; i++)
        {
            // trace2(s[i], right);

            if (s[i] == right)
            {
                pos = true;
                break;
            }
        }

        if (pos)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
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