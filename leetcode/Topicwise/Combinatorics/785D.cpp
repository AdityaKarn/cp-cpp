#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
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
#define MAX 200084
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

    string s;
    cin >> s;

    //finding total open and closed brackets
    lli n = s.size();
    lli totalOpen = 0, totalClose = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            totalOpen++;
        }
    }
    totalClose = n - totalOpen;

    // using the algo
    lli openTillNow = 0;
    lli res = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            openTillNow++;
            continue;
        }
        else if (openTillNow)
        {
            lli closeTillNow = i - openTillNow;
            lli closeAfter = totalClose - closeTillNow;
            res += nCr(closeAfter + openTillNow - 1, openTillNow - 1);
            res %= MOD;
        }
    }

    cout << res;

    return 0;
}