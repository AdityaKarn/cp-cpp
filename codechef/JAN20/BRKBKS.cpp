#include <iostream>
#include <vector>
#include <algorithm>

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

int main()
{
    int t, s, w[5];
    cin >> t;
    while (t--)
    {
        cin >> s;
        int sum = 0;
        for (int i = 1; i <= 3; i++)
        {
            cin >> w[i];
        }

        int ans = 0;

        for (int i = 1; i <= 3; i++)
        {
            if (sum + w[i] <= s)
            {
                sum += w[i];
            }
            else
            {
                ans++;
                sum = w[i];
            }
        }

        if (sum > 0)
        {
            ans++;
        }

        cout << ans << endl;
    }

    return 0;
}
