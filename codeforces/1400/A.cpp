#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        string s;
        cin >> s;

        int k = (s.size() + 1) / 2;

        bool onlyzeros = true, onlyones = true;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                onlyones = false;
            }
            else if (s[i] == '1')
            {
                onlyzeros = false;
            }
        }

        if (onlyzeros == true)
        {
            for (int i = 0; i < k; i++)
            {
                cout << "0";
            }
            cout << "\n";
            continue;
        }

        if (onlyones == true)
        {
            for (int i = 0; i < k; i++)
            {
                cout << "1";
            }
            cout << "\n";
            continue;
        }
        int q = 0;
        for (int i = 0; i < n; i++)
        {
            cout << s[q];
            q += 2;
        }
        cout << "\n";
    }

    return 0;
}