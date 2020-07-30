#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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

    int t, n, prev, cur;
    cin >> t;
    while (t--)
    {
        lli res = 0;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> cur;

            if (i > 0)
            {
                res += abs(cur - prev);
                res--;
            }
            prev = cur;
        }

        cout << res << "\n";
    }
}