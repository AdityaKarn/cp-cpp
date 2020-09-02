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
int a[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        bool inpositive = (a[0] >= 0);
        int minNum = a[0];

        vector<int> pos, neg;
        for (int i = 1; i < n; i++)
        {
            int cur = a[i];

            if (cur >= 0 && inpositive == true)
            {
                minNum = max(minNum, cur);
            }
            if (cur >= 0 && inpositive == false)
            {
                neg.push_back(minNum);
                inpositive = true;
                minNum = cur;
            }
            if (cur < 0 && inpositive == true)
            {
                pos.push_back(minNum);
                inpositive = false;
                minNum = cur;
            }
            if (cur < 0 && inpositive == false)
            {
                minNum = max(minNum, cur);
            }
        }

        if (inpositive)
        {
            pos.push_back(minNum);
        }
        else
        {
            neg.push_back(minNum);
        }

        // for (auto x : pos)
        // {
        //     cout << "psotive" << x << " ";
        // }

        // cout << "\n";

        // for (auto x : neg)
        // {
        //     cout << "negative" << x << " ";
        // }
        // cout << "\n";

        lli res = 0;

        for (auto x : pos)
        {
            res += x;
        }
        for (auto y : neg)
        {
            res += y;
        }

        cout << res << "\n";
    }
    return 0;
}