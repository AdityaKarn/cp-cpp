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

int a[10001], b[10001];

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        sort(a, a + n);
        sort(b, b + n);

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res += min(a[i], b[i]);
        }

        cout << res << endl;
    }
}