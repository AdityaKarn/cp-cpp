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
    int t, n, k, curr;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> curr;

            if ((curr + k) % 7 == 0)
            {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}