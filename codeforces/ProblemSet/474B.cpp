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

int a[100003];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int cur;
    cin >> a[0];
    for (int i = 1; i < n; i++)
    {
        cin >> cur;
        a[i] = cur + a[i - 1];
    }

    //binary search

    int queries, key;
    cin >> queries;

    for (int i = 0; i < queries; i++)
    {
        int ans;
        cin >> key;
        if (key <= a[0])
        {
            cout << 1 << "\n";
            continue;
        }
        else if (key > a[n - 1])
        {
            cout << n << "\n";
            continue;
        }
        int start = 0, end = n - 1;
        int mid = (start + end) / 2;

        while (start <= end)
        {

            mid = (start + end) / 2;

            if (key <= a[mid] && key > a[mid - 1])
            {
                ans = mid + 1;
                break;
            }
            else if (key > a[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}