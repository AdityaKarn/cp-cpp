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

    int t, n;
    cin >> t;

    while (t--)
    {
        int alpha[27];

        for (int i = 0; i <= 26; i++)
        {
            alpha[i] = 0;
        }
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;

            for (char ch : s)
            {
                alpha[ch - 'a']++;
            }
        }

        bool possible = true;
        for (int i = 0; i <= 26; i++)
        {
            if (alpha[i] % n != 0)
            {
                possible = false;
            }
        }
        if (possible)
            cout << "YES\n";
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}