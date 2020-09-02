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

    int n, a, b, c;

    cin >> n >> a >> b >> c;

    int pieces = 0;
    for (int i = 0; i * a <= n; i++)
    {
        for (int j = 0; j * b + i * a <= n; j++)
        {
            int k = (n - j * b - i * a) / c;
            if (i * a + j * b + k * c == n)
            {
                pieces = max(pieces, i + j + k);
            }
        }
    }

    cout << pieces;
    return 0;
}