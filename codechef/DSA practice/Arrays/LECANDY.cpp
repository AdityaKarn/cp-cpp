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

int A[101];

int main()
{
    int t, n, c, sum = 0;

    cin >> t;

    while (t--)
    {
        sum = 0;
        cin >> n >> c;

        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
            sum += A[i];
        }

        if (c >= sum)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}