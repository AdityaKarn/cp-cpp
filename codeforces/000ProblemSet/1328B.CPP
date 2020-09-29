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
    lli n;
    cin >> n;

    lli k;
    cin >> k;

    lli _lamd = 0;

    for (_lamd = 1; _lamd <= n; _lamd++)
    {
        // cout << _lamd << "\n";
        if ((_lamd * (_lamd + 1)) / 2 >= k)
        {
            break;
        }
    }

    lli firstBindex = n - _lamd;
    // cout << firstBindex << " ";

    lli secondBindex = ((_lamd * (_lamd + 1)) / 2) - k;
    secondBindex += firstBindex + 1;
    // cout << secondBindex << "\n";

    for (int i = 1; i <= n; i++)
    {
        if (i == firstBindex || i == secondBindex)
        {
            cout << "b";
        }
        else
        {
            cout << "a";
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