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

bool comp(pair<int, pair<int, int>> o1, pair<int, pair<int, int>> o2)
{
    if (o1.first == o2.first)
    {
        return o1.second.first < o2.second.first;
    }

    return o1.first > o2.first;
}

void solveTestCases()
{
    int n, m;

    cin >> n >> m;
    int res = INT_MAX;

    while (m--)
    {
        int l, r;

        cin >> l >> r;

        res = min(res, r - l);
    }

    cout << res + 1 << "\n";

    int j = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << j << " ";
        j++;

        if (j == res + 1)
        {
            j = 0;
        }
    }

    cout << "\n";
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