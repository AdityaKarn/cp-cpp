#include <iostream>
#include <vector>
#include <algorithm>

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

lli L[101];

int main()
{
    int t, n, k;

    cin >> t;

    while (t--)
    {
        lli totalWeight = 0;
        cin >> n >> k;

        for (int i = 0; i < n; i++)
        {
            cin >> L[i];
            totalWeight += L[i];
        }

        sort(L, L + n);
        lli kid = 0;
        for (int i = 0; i < k; i++)
        {
            kid += L[i];
        }
        lli dad = 0;
        for (int i = n - 1; i > n - k - 1; i--)
        {
            dad += L[i];
        }

        int res = max(abs(totalWeight - 2 * dad), abs(totalWeight - 2 * kid));

        cout << res << endl;
    }
    return 0;
}