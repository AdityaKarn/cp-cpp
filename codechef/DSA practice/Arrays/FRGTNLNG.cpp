#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
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

int FL[101];

int main()
{
    int t, n, k, l;
    vector<string> f;
    string s;
    vector<bool> fExist;
    vector<string>::iterator it;

    cin >> t;

    while (t--)
    {
        f.clear();
        cin >> n >> k;

        for (int i = 0; i < n; i++)
        {
            cin >> s;
            f.push_back(s);
        }

        for (int i = 0; i < k; i++)
        {
            cin >> l;
            for (int j = 0; j < l; j++)
            {
                cin >> s;

                for (int k = 0; k < n; k++)
                {
                    if (s == f[k])
                    {
                        cout << "yes " << k << "\n";
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << fExist[i] << " ";
        }
    }
    return 0;
}