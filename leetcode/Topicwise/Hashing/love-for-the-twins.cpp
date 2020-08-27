#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
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
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;

        unordered_map<int, int> mp;

        int temp, res = 0;

        REP(i, n)
        {
            cin >> temp;

            mp[temp]++;

            if (mp[temp] == 2)
            {
                res += 2;
                mp[temp] -= 2;
            }
        }

        cout << res << "\n";
    }

    return 0;
}