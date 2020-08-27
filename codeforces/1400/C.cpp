//UPSOLVING
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

    int t, x;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        cin >> x;

        string w = string(s.size(), '1');

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                if (i - x >= 0)
                {
                    w[i - x] = '0';
                }
                if (i + x < s.size())
                {
                    w[i + x] = '0';
                }
            }
        }
        string compare = w;

        for (int i = 0; i < s.size(); i++)
        {
            if (i - x >= 0 && w[i - x] == '1' || i + x < s.size() && w[i + x] == '1')
            {
                compare[i] = '1';
            }
            else
            {
                compare[i] = '0';
            }
        }

        if (compare == s)
        {
            cout << w << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
    return 0;
}