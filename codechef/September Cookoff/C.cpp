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

lli a[100001];

void solveTestCases()
{
    int n;
    cin >> n;
    lli res = 0;
    int totalPositive = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        if (a[i] > 0)
        {
            totalPositive++;
            res += a[i];
        }
    }
    vector<int> idx;
    for (int i = 0; i < totalPositive; i++)
    {
        if (a[i] < 0)
        {
            idx.push_back(i);
        }
    }

    for (int i = totalPositive; i < n; i++)
    {
        if (a[i] > 0)
        {
            idx.push_back(i);
        }
    }

    cout << res << "\n";
    cout << idx.size() << " ";
    for (auto x : idx)
    {
        cout << x + 1 << " ";
    }

    cout << "\n";
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