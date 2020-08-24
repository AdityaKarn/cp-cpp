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

lli a[100005];
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<pair<int, int>> v;

        int decreasing = 0, start = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];

            if (a[i] < a[i - 1] && decreasing == 0)
            {
                start = i;
                decreasing = 1;
            }
            if (decreasing == 1 && a[i] > a[i - 1])
            {
                decreasing = 0;
                v.push_back({start, i - 1});
            }
        }

        if (decreasing == 1)
        {
            v.push_back({start, n - 1});
        }

        for (auto x : v)
        {
            cout << x.first << " " << x.second << "\n";
        }
    }
    return 0;
}