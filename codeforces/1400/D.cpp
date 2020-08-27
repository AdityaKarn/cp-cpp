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

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        lli a[3004];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        lli beforeJ[3004], afterK[3004];
        for (int i = 0; i < n; i++)
        {
            beforeJ[a[i]] = 0;
            afterK[a[i]] = 0;
        }

        beforeJ[a[0]]++;
        afterK[a[n - 1]]++;
        lli res = 0;

        for (int j = 1; j < n - 2; j++)
        {
            for (int i = j; i < n - 1; i++)
            {
                afterK[a[i]] = 0;
            }
            afterK[a[n - 1]]++;
            for (int k = n - 2; k > j; k--)
            {
                // cout << "adding" << a[j] << ":" << afterK[a[j]] << "  " << a[k] << ":" << beforeJ[a[k]] << "\n";
                res += beforeJ[a[k]] * afterK[a[j]];

                afterK[a[k]]++;
            }
            beforeJ[a[j]]++;
        }

        cout << res << "\n";
    }

    return 0;
}