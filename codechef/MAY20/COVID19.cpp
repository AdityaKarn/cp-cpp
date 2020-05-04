#include <iostream>
#include <vector>
#include <algorithm>

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

int X[12];
vector<int> v;

int main()
{
    int t, n, m;
    cin >> t;

    while (t--)
    {
        v.clear();
        cin >> n;

        for (int i = 0; i <= 10; i++)
        {
            X[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> m;
            X[m] = 1;
        }

        int cc = 1, idx = 0;
        int iscc = 0;

        for (int idx = 0; idx < 11; idx++)
        {

            if (X[idx] == 1 && iscc > 0)
            {
                cc++;
                iscc = 3;
            }

            if (X[idx] == 1 && iscc == 0)
            {
                cc = 1;
                iscc = 3;
            }

            if (X[idx] == 0 && iscc == 3)
            {
                iscc = 2;
            }

            if (X[idx] == 0 && iscc == 2)
            {
                iscc = 1;
            }
            if (X[idx] == 0 && iscc == 1)
            {
                iscc = 0;
                v.push_back(cc);
                cout << cc << endl;
            }
        }

        sort(v.begin(), v.end());

        // if (v.size() == 1)
        // {
        //     cout << *v.begin() << " " << *v.begin() << endl;
        // }
        // else
        // {
        //     cout << *v.begin() << " " << *v.end() << endl;
        // }
    }
    return 0;
}