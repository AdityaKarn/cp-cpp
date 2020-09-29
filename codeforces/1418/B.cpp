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
int l[101];
int a[101];
void solveTestCases()
{

    int n;
    cin >> n;

    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }
    vector<int> UL;
    for (int i = 0; i < n; i++)
    {
        if (l[i] == 0)
        {
            UL.push_back(a[i]);
        }
    }

    sort(UL.begin(), UL.end(), greater<int>());

    for (int i = 0; i < n; i++)
    {
        if (l[i] == 1)
        {
            cout << a[i] << " ";
        }
        else
        {
            cout << UL[UL.size() - 1] << " ";
            UL.pop_back();
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