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
int arr[50004];

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
    }

    int i = 1, j, k;

    while (i < n)
    {
        j = i + 1;
        k = n;
        while (j < k)
        {
            if (arr[i] + arr[j] <= arr[k])
            {
                break;
            }
            else
            {
                if (k > n)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        i++;
    }

    cout << i << " " << j << " " << k << "\n";
    return 0;
}