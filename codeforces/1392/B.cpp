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
int a[200005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--)
    {
        lli k;
        cin >> n >> k;

        int maxEl = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            maxEl = max(maxEl, a[i]);
        }

        int ans1[n + 1], ans2[n + 1];

        int maxEl2 = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            ans1[i] = maxEl - a[i];
            maxEl2 = max(maxEl2, ans1[i]);
        }

        for (int i = 0; i < n; i++)
        {
            ans2[i] = maxEl2 - ans1[i];
        }

        if (k % 2)
        {
            for (int i = 0; i < n; i++)
            {
                cout << ans1[i] << " ";
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                cout << ans2[i] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}