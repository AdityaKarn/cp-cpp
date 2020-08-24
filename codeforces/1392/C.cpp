#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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

using namespace std;
lli a[200005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;

        vector<pair<int, int>> dec;

        int isdec = 0, start = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];

            if (i > 0 && a[i] < a[i - 1] && isdec == 0)
            {

                start = i;
                isdec = 1;
            }
            else if (i > 0 && a[i] >= a[i - 1] && isdec == 1)
            {
                isdec = 0;
                dec.push_back({start, i - 1});
            }
        }
        if (isdec)
        {
            dec.push_back({start, n - 1});
        }

        lli res = 0;

        for (int i = 0; i < dec.size(); i++)
        {
            int relative = a[dec[i].first - 1];

            int minEl = INT_MAX;

            for (int j = dec[i].first; j <= dec[i].second; j++)
            {
                minEl = min((lli)minEl, a[j]);
            }
            res += relative - minEl;
        }

        cout << res << "\n";
    }
    return 0;
}