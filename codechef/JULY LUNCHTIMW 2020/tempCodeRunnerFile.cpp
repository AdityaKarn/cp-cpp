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

int main()
{
    int t, n, m, x, y;
    cin >> t;

    while (t--)
    {
        cin >> n >> m >> x >> y;

        int first = min(x, y / 2);

        int count = first * m * n;

        if (y % 2 == 0)
        {
            cout << count << "\n";
        }
        else if (y % 2 == 1 && m % 2 == 0)
        {
            int toadd = m / 2;
            toadd *= n;
            cout << count + toadd << "\n";
        }
        else if (y % 2 == 1 && m % 2 == 1)
        {
            int odd = (m / 2) + 1;
            int even = odd - 1;

            int oddrows = n / 2;
            int evenrows = n / 2;

            if (n % 2 == 1)
            {
                oddrows++;
            }

            int toadd = odd * oddrows + even * evenrows;
            cout << count + toadd << "\n";
        }
    }
}