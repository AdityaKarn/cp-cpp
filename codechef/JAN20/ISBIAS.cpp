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

int a[100003];

int main()
{
    int n, q;

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int l, r;
    while (q--)
    {
        cin >> l >> r;
        int count = 0;
        if (a[l + 1] > a[l])
            count++;
        if (a[r] > a[r - 1])
            count++;

        if (count == 1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}