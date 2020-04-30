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

lli a[100001];
lli toGive[100001];

int main()
{
    int t, n;
    lli k;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        lli r = 0;

        //initialise toGive and toTakeS
        for (int i = 0; i < n; i++)
        {
            lli res = a[i] % k;

            toGive[i] = res + toGive[i - 1];
        }

        r = toGive[n - 1] % k;

        cout << r << endl;
    }
}