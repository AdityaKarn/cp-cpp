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

lli a[200005];

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

        int allsame = true;

        for (int i = 0; i < n; i++)
        {
            if (a[i] != a[0])
            {
                allsame = false;
                break;
            }
        }

        if (allsame)
        {
            cout << n << "\n";
        }
        else
        {
            cout << 1 << "\n";
        }
    }

    return 0;
}