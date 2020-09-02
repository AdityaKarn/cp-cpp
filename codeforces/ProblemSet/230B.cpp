#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <math.h>
#include <set>
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
    int t;

    lli n;

    cin >> t;

    while (t--)
    {
        cin >> n;
        set<lli> s;
        bool prime_sieve[1000009];

        for (int i = 1; i <= 1000000; i++)
        {
            prime_sieve[i] = true;
        }

        for (int i = 2; i * i <= 1000000; i++)
        {
            if (prime_sieve[i])
            {
                for (int j = i * i; j <= 1000000; j += i)
                {
                    prime_sieve[j] = false;
                }
            }
        }

        for (int i = 2; i <= 1000000; i++)
        {
            if (prime_sieve[i])
            {
                s.insert(i * i);
            }
        }

        if (s.find(n) != s.end())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}