#include <iostream>
#include <vector>
#include <algorithm>
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

int main()
{
    int t;
    string s;
    cin >> t;

    while (t--)
    {
        cin >> s;

        int len = s.length();

        int i = 0, ans = 0;

        while (i < len)
        {

            if (s[i] != s[i + 1] && i < len - 1)
            {
                ans++;
                i++;
            }
            i++;
        }

        cout << ans << "\n";
    }
    return 0;
}