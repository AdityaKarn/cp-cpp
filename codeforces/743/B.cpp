#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
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
lli k;

int find_res(lli l, lli r, int n)
{
    lli m = l + ((r - l) / (lli)2);

    if (k < m)
    {
        find_res(l, m - 1, n - 1);
    }
    else if (k > m)
    {
        find_res(m + 1, r, n - 1);
    }
    else
    {
        return n;
    }
}

void solveTestCases()
{
    int n;

    cin >> n;
    cin >> k;

    lli r = 1;

    for (int i = 0; i < n - 1; i++)
    {
        r = r * (lli)2 + (lli)1;
    }

    cout << find_res(1, r, n) << "\n";
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