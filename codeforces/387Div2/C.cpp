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
    lli n, q;
    cin >> n >> q;

    vector<lli> v(n, 0);

    while (q--)
    {
        lli t, k, d;
        cin >> t >> k >> d;

        lli available = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] < t)
            {
                available++;
            }
        }

        if (available < k)
        {
            cout << "-1\n";
            continue;
        }

        lli ct = 0;
        lli sum = 0;

        for (int i = 0; i < n; i++)
        {
            if (ct >= k)
            {
                break;
            }
            if (v[i] < t)
            {
                v[i] = t + d - 1;
                ct++;
                sum += i + 1;
            }
        }

        cout << sum << "\n";
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