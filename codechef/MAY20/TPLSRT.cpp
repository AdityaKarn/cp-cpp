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

int p[200002];
int idx[200002];

bool isSorted(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (a[i + 1] < a[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t, n, k, res = 0;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        for (int i = 1; i <= n; i++)
        {
            cin >> p[i];
            idx[p[i]] = i;
        }

        for (int i = 1; i < n; i++)
        {
            if (isSorted(p, n))
            {
                break
            }

            if (p[i] != i)
            {
                int a = p[i];
                int b = idx[p[i]];
            }
        }
    }

    return 0;
}