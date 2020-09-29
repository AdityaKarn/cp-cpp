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
lli Nice[32];
void init()
{
    lli j = 2;
    Nice[0] = 1;
    for (int i = 1; i <= 31; i++)
    {
        Nice[i] = Nice[i - 1] * 2 + (j * j);
        j += 2;
    }
}

void solveTestCases()
{
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << Nice[i] << " ";
    // }

    int cnt = 0;
    lli x;
    cin >> x;

    for (int i = 0; i < 31; i++)
    {
        if (x - Nice[i] >= 0)
        {
            cnt++;
            x -= Nice[i];
        }
        else
        {
            break;
        }
    }
    cout << cnt << "\n";
}

int main()
{
    init();
    // IOS;
    int t;
    cin >> t;

    while (t--)
    {
        solveTestCases();
    }

    return 0;
}