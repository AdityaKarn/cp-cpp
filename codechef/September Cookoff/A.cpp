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
    int n, l, k;

    cin >> n >> k >> l;

    if (k == 1)
    {
        if (n == 1)
        {
            cout << "1\n";
            return;
        }
        else
        {
            cout << "-1\n";
            return;
        }
    }
    if (k * l < n)
    {
        cout << "-1\n";
        return;
    }
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        cout << j << " ";
        j++;
        if (j == k + 1)
        {
            j = 1;
        }
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