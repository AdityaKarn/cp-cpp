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

lli arr[100001];
int len[100001];

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            if (arr[i] >= 0)
            {
                arr[i] = 1;
            }
            else
            {
                arr[i] = -1;
            }
        }

        len[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] * arr[i + 1] < 0)
            {
                len[i] = len[i + 1] + 1;
            }
            else
            {
                len[i] = 1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << len[i] << " ";
        }

        cout << "\n";
    }
    return 0;
}