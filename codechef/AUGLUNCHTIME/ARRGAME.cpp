#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include <cmath>
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
int a[300005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        //to find longest continuos zeros
        int longest = 0, start = 0;
        vector<int> v;
        bool isinzeros = false;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0 && isinzeros == false)
            {
                start = i;
                isinzeros = true;
            }
            if (a[i] == 1 && isinzeros == true)
            {
                isinzeros = false;
                longest = max(longest, i - start);
                v.push_back(i - start);
            }
        }

        if (isinzeros)
        {
            v.push_back(n - start);
            longest = max(longest, n - start);
        }
        sort(v.begin(), v.end(), greater<int>());

        // for (auto x : v)
        // {
        //     cout << x << " ";
        // }

        if (v.empty())
        {
            cout << "No\n";
        }
        else if (v.size() == 1)
        {
            if (longest % 2 == 0)
            {
                cout << "No\n";
            }
            else
            {
                cout << "Yes\n";
            }
        }
        else if (v.size() > 1)
        {
            if (v[0] % 2 == 1 && (v[0] + 1) / 2 > v[1])
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }

    return 0;
}