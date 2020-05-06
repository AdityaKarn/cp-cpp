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
#define INF 1000000

using namespace std;

int W[10001];

int main()
{
    int t, n, minV = INF;
    cin >> t;

    while (t--)
    {
        minV = INF;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> W[i];
            minV = min(minV, W[i]);
        }

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            count += W[i] - minV;
        }
        cout << count << endl;
    }

    return 0;
}