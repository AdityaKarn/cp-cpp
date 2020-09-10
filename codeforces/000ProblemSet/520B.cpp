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

void solveTestCases()
{
    int n, m;
    cin >> n >> m;

    if (m <= n)
    {
        cout << n - m << "\n";
        return;
    }

    lli res = 0;

    while (m > n)
    {

        if (m % 2 == 0)
        {
            m /= 2;
            res++;
        }
        else
        {
            m += 1;
            res++;
        }
    }

    res += n - m;

    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t = 1;

    while (t--)
    {
        solveTestCases();
    }

    return 0;
}