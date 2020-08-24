#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
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

int fact[50000];

void facInit()
{
    fact[1] = 1;
    for (int i = 2; i < 50000; i++)
    {
        fact[i] = fact[i - 1] * i;
    }
}

int ncr(int n, int r)
{
    return (fact[n] / (fact[r] * fact[n - r]));
}

int main()
{
    facInit();
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;

        map<int, int> freq;
        int cur;
        for (int i = 0; i < n; i++)
        {
            cin >> cur;
            freq[cur]++;
        }

        lli res = 0;

        for (auto x : freq)
        {
            int cur = x.first;
            int curfreq = x.second;

            for (auto y : freq)
            {
                int comp = y.first;
                int compfreq = y.second;

                if (cur > comp)
                {
                    for (int i = 2; i <= curfreq; i++)
                    {
                        for (int j = 1; j <= i - 1; j++)
                        {
                            cout << "adding " << curfreq << " " << i << " ka ncr and " << compfreq << " " << j << "\n";
                            res += (ncr(curfreq, i) * ncr(compfreq, j)) % mod;
                        }
                    }
                }

                else if (cur == comp)
                {
                    for (int i = 1; i <= curfreq; i++)
                    {
                        cout << "adding " << curfreq << " " << i << " ka ncr"
                             << "\n";
                        res += (ncr(curfreq, i)) % mod;
                    }
                }

                else
                {
                    continue;
                }
            }
        }

        cout << res << "\n";
    }

    return 0;
}