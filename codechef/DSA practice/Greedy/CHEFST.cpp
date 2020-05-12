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
    int t;
    cin >> t;
    lli n1, n2, m;

    while (t--)
    {
        cin >> n1 >> n2 >> m;

        while (m)
        {
            if (n1 - m >= 0 && n2 - m >= 0)
            {
                n1 -= m;
                n2 -= m;
                m--;
            }
            else
            {
                break;
            }
        }

        cout << n1 + n2 << endl;
    }
    return 0;
}