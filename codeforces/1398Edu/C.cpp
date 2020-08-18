#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
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

int arr[100001];
int p[100001];

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int t, n;
    cin >> t;
    string s;
    while (t--)
    {
        cin >> n;
        cin >> s;

        map<lli, lli> mp;
        mp[0]++;

        lli p = 0;
        for (int i = 0; i < n; i++)
        {
            p += s[i] - '0';
            mp[p - i - 1]++;
        }
        lli ans = 0;
        for (auto y : mp)
        {
            ans += (y.second) * (y.second - 1) / 2;
        }

        cout << ans << "\n";
    }

    return 0;
}