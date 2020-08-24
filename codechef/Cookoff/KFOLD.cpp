#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, n, k;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        string s;
        cin >> s;

        if (n % k != 0)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        int freqzero = 0, freqone = 0;

        for (char ch : s)
        {
            if (ch == '0')
            {
                freqzero++;
            }
            else
            {
                freqone++;
            }
        }

        int segments = n / k;
        if (freqzero % segments)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        string res;

        int noOfzeros = freqzero / segments;
        int noOfones = freqone / segments;

        while (noOfzeros--)
        {
            res += '0';
        }
        while (noOfones--)
        {
            res += '1';
        }

        while (segments--)
        {
            cout << res, reverse(res.begin(), res.end());
        }

        cout << "\n";
    }

    return 0;
}