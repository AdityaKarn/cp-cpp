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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    int a[11];

    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (a[j] & (1 << i))
                {
                    count++;
                }
            }
            ans += 2 * count * (n - count);
        }

        cout << ans << "\n";
    }

    return 0;
}