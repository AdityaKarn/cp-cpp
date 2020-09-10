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

int a[100001];
lli pr[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n >> t;

    pr[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        pr[i] = a[i] + pr[i - 1];
    }

    if (pr[n] <= t)
    {
        cout << n << "\n";
        return 0;
    }
    int i = 0, j;
    int ans = 0;

    for (i = 1; i <= n; i++)
    {
        if (a[i] > t)
            continue;
        int l = i, r = n; // find j
        while (l < r)
        {
            int mid = (l + r) >> 1;
            mid++;
            if (pr[mid] - pr[i - 1] <= t)
                l = mid;
            else
                r = mid - 1;
        }
        ans = max(ans, l - i + 1);
    }

    cout << ans << "\n";

    return 0;
}