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

int main()
{
    int t, x, y, n, k, p, c;
    cin >> t;

    while (t--)
    {
        cin >> x >> y >> k >> n;

        int pagesNeeded = x - y;
        bool lucky = false;

        for (int i = 0; i < n; i++)
        {
            cin >> p >> c;

            if (p >= pagesNeeded && c <= k)
            {
                lucky = true;
            }
        }

        if (lucky)
            cout << "LuckyChef\n";
        else
            cout << "UnluckyChef\n";
    }

    return 0;
}