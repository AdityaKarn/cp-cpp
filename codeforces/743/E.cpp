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

int a[1001];

int greatestConti[9];

void solveTestCases()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= 8; i++)
    {
        greatestConti[i] = 0;
    }

    bool conti = a[1] == a[0];
    greatestConti[a[0]] = 1;
    int size = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1] && conti == true)
        {
            size++;
        }
        else if (a[i] == a[i - 1] && conti == false)
        {
            conti = true;
            size++;
        }
        else if (a[i] != a[i - 1] && conti == true)
        {
            conti = false;
            greatestConti[a[i]] = max(greatestConti[a[i]], size);
            size = 1;
        }
        else if (a[i] != a[i - 1] && conti == false)
        {
            greatestConti[a[i]] = max(greatestConti[a[i]], size);
            size = 1;
        }
    }

    if (conti == true)
    {
        greatestConti[a[n - 1]] = max(greatestConti[a[n - 1]], size);
    }

    for (int i = 1; i <= 8; i++)
    {
        cout << i << " : " << greatestConti[i] << "\n";
    }
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