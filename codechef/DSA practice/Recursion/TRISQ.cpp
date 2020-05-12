#include <iostream>
#include <vector>
#include <algorithm>

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
    int t, n;
    cin >> t;
    int N[32];
    while (t--)
    {
        cin >> n;
        n += 3;
        int y = 0, x = 0, prev;
        int count = 0;

        prev = n / 2;
        prev *= 2;

        while (y <= n)
        {
            x = prev;
            while (x >= 0)
            {
                if (abs(n - (x + y)) > 4)
                {
                    count += (x / 2);
                    prev = x;
                    break;
                }
                else
                {
                    x -= 2;
                }
            }
            y += 2;
        }

        cout << count << "\n";
    }
    return 0;
}