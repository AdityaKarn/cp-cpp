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

void solveTestCases()
{
    int l, r, m;
    cin >> l >> r >> m;

    if (l > r)
    {
        swap(l, r);
    }
    int bMinusCRange = r - l;
    int i = 0, j = l;
    bool possible = false;
    int nIntoA;
    for (i = 0; i <= bMinusCRange; i++)
    {

        nIntoA = m + i;

        for (j = l; j <= r; j++)
        {
            if (nIntoA % j == 0)
            {
                possible = true;
                break;
            }
        }
        if (possible)
            break;
    }

    int b = l + i;
    int c = l;
    int a = j;

    cout << a << " " << c << " " << b << "\n";
}

int main()
{
    // IOS;
    int t;
    cin >> t;

    while (t--)
    {
        solveTestCases();
    }

    return 0;
}