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

int arr[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, n, k;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        bool impossible = false;
        int w, current_load = 0, trips = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            w = arr[i];

            if (w > k)
            {
                impossible = true;
                break;
            }

            if (w + current_load > k)
            {
                trips++;
                current_load = w;
            }
            else
            {
                current_load += w;
            }
        }

        if (current_load)
        {
            trips++;
        }

        if (impossible)
            cout << -1 << "\n";
        else
        {
            cout << trips << "\n";
        }
    }

    return 0;
}