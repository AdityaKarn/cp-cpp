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

lli L[100001];

int main()
{
    int n;
    lli d;
    cin >> n >> d;

    for (int i = 0; i < n; i++)
    {
        cin >> L[i];
    }

    sort(L, L + n);
    int count = 0;

    int i = 0;
    while (i < n - 1)
    {

        if (L[i + 1] - L[i] <= d)
        {
            count++;
            i += 2;
        }
        else
        {
            i += 1;
        }
    }
    cout << count;

    return 0;
}