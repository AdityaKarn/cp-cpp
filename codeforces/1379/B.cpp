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
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
lli l, r, m;
lli A, B, C;

bool check(int n, int a)
{
    if (n == 0)
        return 0;

    A = a;

    int diff = m - (n * a);

    if (abs(diff) > r - l)
    {
        return 0;
    }

    if (diff > 0)
    {
        C = l;
        B = l + diff;
    }
    else
    {
        C = r;
        B = r - abs(diff);
    }
    return 1;
}
void solveTestCases()
{
    cin >> l >> r >> m;

    for (int i = l; i <= r; i++)
    {
        int n = m / i;

        if (check(n, i))
        {
            cout << A << " " << B << " " << C << "\n";
            break;
        }
        if (check(n + 1, i))
        {
            cout << A << " " << B << " " << C << "\n";
            break;
        }
    }
    return;
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