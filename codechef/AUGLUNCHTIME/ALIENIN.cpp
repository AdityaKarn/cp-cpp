#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>
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
vector<long long> ci;
int n, c;

bool possible(long double cd)
{
    long double time_stamp = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (time_stamp < ci[i])
        {
            time_stamp = ci[i] + cd;
        }
        else if (time_stamp <= ci[i] + c)
        {
            time_stamp += cd;
        }
        else
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> c;
        ci.clear();
        ci.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> ci[i];
        }

        sort(ci.begin(), ci.end());

        long double start = 0, end = 1e18;
        long double mid = (start + end) / 2.0;

        for (int i = 0; i < 100; i++)
        {
            mid = (start + end) / 2.0;

            if (possible(mid))
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }

        cout << fixed << setprecision(10) << start << "\n";
    }

    return 0;
}