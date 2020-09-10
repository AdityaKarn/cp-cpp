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

long long BinaryExponentiation(long long num, long long raise, long long modulo)
{
    long long result = 1;
    while (raise > 0)
    {
        if (raise & 1)
            result = (result * num) % modulo;
        num = (num * num) % modulo;
        raise = (raise >> 1);
    }
    return result;
}

void solveTestCases()
{
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> distance(n);

    distance[0].push_back(1);
    int node_dist;
    for (int i = 2; i <= n; i++)
    {
        cin >> node_dist;
        distance[node_dist].push_back(i);
    }

    //first make satisfiable trees
    bool pos = true;
    long long ans = 1;

    for (int i = 1; i <= n - 1; i++)
    {
        if (distance[i].size())
        {
            ans *= BinaryExponentiation(distance[i - 1].size(), distance[i].size(), mod);
        }
        if (distance[i].size() && !(distance[i - 1].size()))
        {
            pos = false;
        }
        ans = (ans % mod);
    }

    if (!pos)
    {
        cout << "0\n";
        return;
    }

    // now ways to add edges
    long long node_pairs = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        long long count = distance[i].size();
        node_pairs += ((count) * (count - 1)) / 2;
    }

    if (m - (n - 1))
    {
        m -= (n - 1);
        if (m > node_pairs)
        {
            ans = 0;
        }
        else
        {
            long long ways = 0;
            long long numerator = 1, denominator = 1;

            for (long long i = node_pairs - m + 1; i <= node_pairs; i++)
            {
                numerator *= i;
                numerator %= mod;
            }
            for (long long i = 1; i <= m; i++)
            {
                denominator *= i;
                denominator %= mod;
            }
            ways = numerator * BinaryExponentiation(denominator, mod - 2, mod);
            ways %= mod;
            ans = (ans * ways) % mod;
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--)
    {
        solveTestCases();
    }

    return 0;
}