#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>
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

double arr[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, l;
    cin >> n >> l;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    double maxI = -1.0;

    for (int i = 0; i < n - 1; i++)
    {
        maxI = max((arr[i + 1] - arr[i]) / 2, maxI);
    }

    cout << fixed << setprecision(9) << max(arr[0] - 0, max(maxI, l - arr[n - 1])) << "\n";

    return 0;
}