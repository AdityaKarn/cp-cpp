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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        string s;

        cin >> n >> s;

        int count = 0;
        while (s.size() && s[0] == s.back())
        {
            count++;
            s.pop_back();
        }

        if (s.empty())
        {
            if (count <= 2)
            {
                cout << "0\n";
                continue;
            }
            if (count == 3)
            {
                cout << "1\n";
                continue;
            }

            cout << (count + 2) / 3 << "\n";
            continue;
        }

        s.push_back('$');
        lli ans = 0;
        for (int i = 0; i + 1 < s.size(); i++)
        {
            count++;

            if (s[i] != s[i + 1])
            {
                ans += count / 3;
                count = 0;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}