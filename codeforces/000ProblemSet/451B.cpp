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
    int n;
    cin >> n;
    vector<int> A(n + 1);

    vector<pair<int, int>> e;
    bool isDec = false;
    int start = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (i < n && A[i] > A[i + 1] && isDec == false)
        {
            start = i;
            isDec = true;
        }
        if (i < n && A[i] < A[i + 1] && isDec == true)
        {
            e.push_back({start, i});
            break;
        }
    }
    if (e.empty() && isDec == true)
    {
        e.push_back({start, n});
    }

    // cout << e[0].first << " " << e[0].second;
    if (!e.empty())
        reverse(A.begin() + e[0].first, A.begin() + e[0].second + 1);

    for (int i = 1; i < n; i++)
    {
        if (A[i] > A[i + 1])
        {
            cout << "no\n";
            return;
        }
    }

    if (e.empty())
    {
        cout << "yes\n";
        cout << "1 1\n";
    }
    else
    {
        cout << "yes\n";
        cout << e[0].first << " " << e[0].second << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t = 1;

    while (t--)
    {
        solveTestCases();
    }

    return 0;
}