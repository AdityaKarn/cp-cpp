#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define REP(i, n) for (int i = 1; i <= n; i++)

#define MOD 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define MAX 2000012

using namespace std;

long long fact[MAX], invFact[MAX];

lli nCr(lli n, lli r)
{
    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    lli i;

    fact[0] = invFact[0] = invFact[1] = 1;
    for (i = 1; i < MAX; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    for (i = 2; i < MAX; i++)
        invFact[i] = (MOD - MOD / i) * invFact[MOD % i] % MOD;
    for (i = 1; i < MAX; i++)
        invFact[i] = (invFact[i - 1] * invFact[i]) % MOD;

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;

        cin >> n >> k;

        //
        cout << ((2LL * nCr(n + k + 1, k + 2)) % MOD - n + MOD) % MOD << "\n";
    }

    return 0;
}