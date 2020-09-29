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
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int main()
{
    IOS;

    int t;
    cin >> t;

    // int temp;
    while (t--)
    {
        string s;

        for (int i = 0; i < 9; i++)
        {
            cin >> s;

            for (char c : s)
            {
                if (c == '9')
                {
                    cout << 1;
                }
                else
                {
                    cout << c;
                }
            }
            cout << "\n";
        }
    }

    return 0;
}