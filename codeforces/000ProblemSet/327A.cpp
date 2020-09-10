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

    int n;
    cin >> n;

    bool isinzero = false;
    int curr;
    vector<int> v;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> curr;

        if (curr == 1 && isinzero == true)
        {
            isinzero = false;
            v.push_back(i - start);
            start = i;
        }
        if (curr == 0 && isinzero == false)
        {
            isinzero = true;
            v.push_back(i - start);
            start = i;
        }
    }
    v.push_back(n - start);

    // for (auto x : v)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";

    int m = v.size();

    if (m == 1)
    {
        cout << v[0] - 1 << "\n";
    }
    else
    {

        //subarray where evenSum - oddSum is max, store start index and last index
        int l, r, max = 0;
        for (int i = 1; i < m; i += 2)
        {
            int oddsum = 0, evenSum = 0;
            for (int j = i; j < m; j++)
            {
                if (j % 2 == 1)
                {
                    oddsum += v[j];
                }
                else
                {
                    evenSum += v[j];
                }

                if (oddsum - evenSum > max)
                {
                    // cout << "oddsum and evenSum:" << oddsum << " " << evenSum << "\n";
                    max = oddsum - evenSum;
                    l = i;
                    r = j;
                }
            }
        }

        // cout << l << " " << r << "\n";

        int res = 0;

        for (int i = 0; i < l; i++)
        {
            if (i % 2 == 0)
            {
                res += v[i];
            }
        }

        for (int i = l; i <= r; i++)
        {
            if (i % 2 == 1)
            {
                res += v[i];
            }
        }

        for (int i = r + 1; i < m; i++)
        {
            if (i % 2 == 0)
            {
                res += v[i];
            }
        }

        cout << res;
    }
    return 0;
}