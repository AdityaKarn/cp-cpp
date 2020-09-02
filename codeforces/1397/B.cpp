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

int power(int x, unsigned int y)
{
    int res = 1; // Initialize result

    x = x % mod; // Update x if it is more than or
                 // equal to p

    if (x == 0)
        return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % mod;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % mod;
    }
    return res;
}

bool isPerfectSquare(int n)
{
    for (int i = 1; i * i <= n; i++)
    {

        // If (i * i = n)
        if ((n % i == 0) && (n / i == i))
        {
            return true;
        }
    }
    return false;
}

int arr[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    bool onePresent = false;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 1)
        {
            onePresent = true;
        }
    }

    sort(arr, arr + n);

    int lastElement = arr[n - 1];
    int c;
    for (int i = 2; i < lastElement; i++)
    {
        if (power(i, n - 1) > lastElement)
        {
            c = i;
            break;
        }
    }
    // cout << c << "\n";
    lli res = 0;

    for (int i = 0; i < n; i++)
    {
        res += abs(power(c, i) - arr[i]);
    }

    cout << res;

    return 0;
}