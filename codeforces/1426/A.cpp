#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
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
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
const int MAX = (int)1e4 + 5;
void solveTestCases()
{
    int n, x;
    cin >> n >> x;

    if (n == 1 || n == 2)
    {
        cout << "1\n";
        return;
    }
    lli res = 1;

    n -= 2;

    // cout << "n" << n << "\n";
    res += n / x;

    n -= x * (n / x);
    // cout << "n" << n << "\n";

    if (n > 0)
    {
        res++;
    }

    cout << res << "\n";
}

int main()
{
    IOS;
    int t;
    cin >> t;

    while (t--)
    {
        solveTestCases();
    }

    return 0;
}