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

void solveTestCases()
{
    int n, a, b;
    cin >> n >> a >> b;

    int d;

    int i = 1, j = n;
    bool pos = true;
    bool toDecre = false;

    int common_difference;
    for (j = n; j >= 2; j--)
    {

        for (i = 1; i <= n - 1; i++)
        {
            // cout << b - a << " " << j << " " << i << "jaojo\n";

            if ((b - a) % (j - i) == 0)
            {
                pos = false;
                break;
            }
            common_difference = (b - a) / (j - i);

            if ((a - (i - 1) * common_difference) < 0)
            {
                pos = false;
                toDecre = true;
                break;
            }
        }
        if (!pos)
        {
            break;
        }
    }

    if (toDecre)
    {
        while (j > i)
        {

            // cout << b - a << " " << j << " " << i << "jm\n";

            if ((b - a) % (j - i) == 0)
            {
                break;
            }
            common_difference = (b - a) / (j - i);

            j = j - 1;
        }
    }
    // cout << i << j << "\n";
    common_difference = (b - a) / (j - i);

    int first_term = a - (i - 1) * common_difference;
    // cout << first_term;

    if (first_term < 1)
    {
        int guess = (1 - first_term) / common_difference;
        int alter = first_term + guess * common_difference;
        // cout << alter;

        for (int q = guess; q <= n; q++)
        {
            // cout << "alter   " << alter << "\n";
            alter = first_term + (q * common_difference);

            if (alter >= 1)
            {
                break;
            }
        }

        for (int p = 1; p <= n; p++)
        {
            cout << alter + (p - 1) * common_difference << " ";
        }
        cout << "\n";
        return;
    }

    for (int p = 1; p <= n; p++)
    {
        cout << first_term + (p - 1) * common_difference << " ";
    }
    cout << "\n";
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    cin >> t;

    while (t--)
    {
        solveTestCases();
    }

    return 0;
}