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

int sum(lli num)
{
    int res = 0;

    while (num)
    {
        res += num % 10;
        num /= 10;
    }
    return res;
}

void solveTestCases()
{
    lli n;
    int s;
    cin >> n >> s;

    if (sum(n) <= s)
    {
        cout << "0\n";
        return;
    }

    lli ans = 0;
    lli pw = 1;

    for (int i = 0; i < 18; i++)
    {
        int dig = (n / pw) % 10;

        lli add = pw * ((10 - dig) % 10);

        ans += add;
        n += add;

        if (sum(n) <= s)
        {
            break;
        }
        pw *= 10;
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--)
    {
        solveTestCases();
    }

    return 0;
}