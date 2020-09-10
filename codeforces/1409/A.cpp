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
    lli a, b;

    cin >> a >> b;

    int c = abs(a - b) / 10;

    if ((a - b) % 10 == 0)
    {
        cout << c << "\n";
        return;
    }
    else
    {
        cout << c + 1 << "\n";
    }
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