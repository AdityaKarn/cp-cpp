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

int freq[27]; // a= 0, b = 1,...z = 25

int main()
{
    int t, n, q, c;
    string exp;
    cin >> t;

    while (t--)
    {
        cin >> n >> q;

        for (int i = 0; i < 26; i++)
        {
            freq[i] = 0;
        }

        cin >> exp;

        for (int i = 0; i < n; i++)
        {
            char ch = exp[i];

            int idx = ch - 'a';

            freq[idx]++;
        }

        while (q--)
        {
            cin >> c;
            int count = 0;
            for (int j = 0; j <= 25; j++)
            {
                if (freq[j] - c > 0)
                {
                    count += freq[j] - c;
                }
            }

            cout << count << endl;
        }
    }
    return 0;
}
