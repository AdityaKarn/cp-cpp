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

int a[31];
int incl, excl;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        incl = a[0];
        excl = 0;

        for (int i = 1; i < n; i++)
        {
            int incl_new = a[i] + min(excl, incl);

            int excl_new = incl;

            incl = incl_new;
            excl = excl_new;
        }
        cout << min(incl, excl) << "\n";
    }
    return 0;
}