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

int A[1000001];

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        if (next_permutation(A, A + n))
        {
            for (int i = 0; i < n; i++)
            {
                cout << A[i];
            }
        }
        else
        {
            cout << "-1";
        }

        cout << "\n";
    }

    return 0;
}