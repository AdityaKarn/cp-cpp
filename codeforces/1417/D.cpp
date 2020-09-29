#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <array>
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
const int MAX = (int)1e4 + 5;
vector<array<int, 3>> ans;
int arr[MAX];
int n;

int change(int x, int y, int z)
{
    arr[x] -= x * z;
    arr[y] += x * z;
    ans.push_back({x, y, z});
}

void solveTestCases()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    ans.clear();

    lli sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += arr[i];
    }

    if (sum % n != 0)
    {
        cout << "-1\n";
        return;
    }

    //first task

    for (int i = 2; i <= n; i++)
    {
        if (arr[i] % i)
        {
            change(1, i, i - arr[i] % i);
        }

        change(i, 1, arr[i] / i);
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    for (int i = 2; i <= n; i++)
    {
        change(1, i, sum / n);
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    cout << ans.size() << "\n";
    for (auto m : ans)
    {
        for (int i = 0; i <= 2; i++)
        {
            cout << m[i] << " ";
        }
        cout << "\n";
    }
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