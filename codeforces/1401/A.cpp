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

    int t, n, k;
    cin >> t;

    while (t--)
    {

        cin >> n >> k;

        int rem = (n - k);

        if (rem >= 0 && rem % 2 == 0)
        {
            cout << "0\n";
            continue;
        }

        if (rem > 0)
        {
            cout << "1\n";
            continue;
        }

        if (rem < 0)
        {
            cout << abs(n - k) << "\n";
            continue;
        }
    }

    return 0;
}