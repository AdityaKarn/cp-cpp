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

int arr[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int bar1 = 1, bar2 = n - 1;

    int len1 = 1, len3 = 1;
    int len2 = n - len1 - len3;
    bool possible = false;
    for (int i = 1; i < n - 1; i++)
    {
        //to check whether we can take a[i]

        for (int j = 0; j <= bar1; j++)
        {
            // cout << len2 << " " << len1 << " " << arr[j] << "\n";
            if ((len2 + len1 - arr[j]) % len2 != 0 && (len2 + len1 - arr[j]) % len1 != 0)
            {
                break;
            }

            bar1++;
            len1++;
        }
    }

    for (int i = n - 1; i > len1; i--)
    {
        for (int j = n - 1; j >= bar2; j--)
        {
            if ((len2 + len3 - arr[j]) % len2 != 0 && (len2 + len3 - arr[j]) % len3 != 0)
            {
                break;
            }
        }
        bar2--;
        len2++;
    }

    cout << 0 << " " << len1 - 1 << "\n";

    if (len1 == 1)
    {
        cout << 1 << " " << 1 << "\n";
        cout << -arr[0] << "\n";
    }
    else
    {
        cout << 1 << " " << len1 << "\n";
        for (int i = 0; i < len1 - 1; i++)
        {
            cout << arr[i] % len1 << "\n";
        }
        cout << "\n";
    }
    if (len1 == 1)
    {
    }
    for (int i = 0; i < len1; i++)
    {
        cout << (len2 + len1 - arr[i]) << " ";
        arr[i] += arr[i] % len2;
    }

    cout << "\n";
    cout << 0 << " " << len2 << "\n";
    for (int i = 0; i < n - 1; i++)
    {
        cout << -1 * arr[i] << " ";
    }
    cout << "\n";
    cout << len3 << " " << len3 << "\n";

    cout << -1 * arr[n - 1];

    // cout << bar1;
    return 0;
}