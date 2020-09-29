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
vector<int> cnt(101);
void solveTestCases()
{
    int n;
    cin >> n;

    for (int i = 0; i <= 100; i++)
    {
        cnt[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        cnt[temp]++;
    }

    if (cnt[0] == 0)
    {
        cout << "0\n";
        return;
    }
    else if (cnt[0] == 1)
    {
        for (int i = 1; i <= 100; i++)
        {
            if (cnt[i] == 0)
            {
                cout << i << "\n";
                return;
            }
        }
    }

    int a = 0, b = 0;
    for (int i = 0; i <= 100; i++)
    {
        if (cnt[i] >= 2)
        {
            continue;
        }
        else
        {
            b = i;
            break;
        }
    }

    for (int i = 0; i <= 100; i++)
    {
        if (cnt[i] == 0)
        {
            a = i;
            break;
        }
    }
    cout << a + b << "\n";
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