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

        lli x, y;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
        }

        int res = n, parent_sides = n;
        while (true)
        {
            if (parent_sides <= 5)
            {
                break;
            }

            int child_sides = parent_sides / 2;

            res += child_sides;
            parent_sides = child_sides;
        }

        cout << res << "\n";
    }
    return 0;
}