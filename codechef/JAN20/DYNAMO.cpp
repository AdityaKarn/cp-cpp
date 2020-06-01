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

#define INF 1000000000

using namespace std;
using ll = unsigned long long int;

ll power(ll a, int x)
{
    ll res = 1ll;
    for (int i = 0; i < x; ++i)
    {
        res = a * res;
    }
    return res;
}

int main()
{
    int t, n;
    ll a, b, d;
    cin >> t;

    while (t--)
    {
        cin >> n;

        ll tenN = power(10ll, n);

        cin >> a;

        cout << a + 2 * tenN << endl;

        cin >> b;

        cout << tenN - b << endl;

        cin >> d;

        cout << tenN - d << endl;

        int ok;
        cin >> ok;
    }

    return 0;
}