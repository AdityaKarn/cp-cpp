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
const int MAX = 1e5 + 1;
int a[MAX];

void solveTestCases()
{
    int n;
    cin >> n;
    int NegaTiveCount = 0;
    int zeroCount = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] <= -1)
        {
            NegaTiveCount++;
        }
        if (a[i] == 0)
        {
            zeroCount++;
        }
    }
    lli res = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            res += a[i] - 1;
        }
        else if (a[i] < 0)
        {
            res += abs(a[i] + 1);
        }
    }

    if (NegaTiveCount % 2 == 0)
    {
        res += zeroCount;
    }
    else
    {
        if (zeroCount > 0)
        {
            res += zeroCount;
        }
        else
        {
            res += zeroCount + 2;
        }
    }

    cout << res << "\n";
}

int main()
{
    IOS;
    int t;
    t = 1;

    while (t--)
    {
        solveTestCases();
    }

    return 0;
}