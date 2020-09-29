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

int A[1001];

void solveTestCases()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    sort(A, A + n);

    int toAdd = A[0];

    if (A[0] > k)
    {
        cout << "0\n";
        return;
    }

    int i = 1;
    lli res = 0;
    while (i < n)
    {
        // cout << i << " " << A[i] << " " << A[0] << "\n";
        if (A[i] + toAdd <= k)
        {
            A[i] += toAdd;
            res++;
        }
        else
        {
            i++;
        }
    }

    cout << res << "\n";
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