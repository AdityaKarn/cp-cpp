#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
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
int A[100005];

void solveTestCases()
{
    int n, T;

    cin >> n >> T;

    vector<int> color(n, 0);
    vector<int> less, eq, more;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        if (A[i] < T / 2)
        {
            less.push_back(i);
        }
        else if (A[i] > T / 2)
        {
            more.push_back(i);
        }
        else if (T % 2 == 0 && A[i] == T / 2)
        {
            eq.push_back(i);
        }
    }

    for (auto each : more)
    {
        color[each] = 1;
    }

    int sz = eq.size();

    for (int i = 0; i < sz / 2; i++)
    {
        int idx = eq[i];

        color[idx] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << color[i] << " ";
    }
    cout << "\n";
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