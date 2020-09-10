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
    int a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;

    if (a < b)
    {
        swap(a, b);
        swap(x, y);
    }

    int toDecreaseFromB = max(y, b - n);

    n -= b - toDecreaseFromB;

    b = toDecreaseFromB;

    // cout << b << " " << toDecreaseFromB << " " << n;

    a = max(x, a - n);

    lli res = (lli)a * (lli)b;

    cout << res << "\n";
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    cin >> t;

    while (t--)
    {
        solveTestCases();
    }

    return 0;
}