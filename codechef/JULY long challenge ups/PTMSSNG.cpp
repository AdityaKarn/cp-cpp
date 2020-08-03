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
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;

        int x, y, resx = 0, resy = 0;
        for (int i = 0; i < 4 * n - 1; i++)
        {
            cin >> x >> y;
            resx ^= x;
            resy ^= y;
        }

        cout << resx << " " << resy << "\n";
    }
    return 0;
}
