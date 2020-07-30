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
int a[1003];
int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        int fives = 0, tens = 0, cur;
        bool isPossible = true;
        cin >> n;

        for (int i = 0; i < n; i++)
        {

            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cur = a[i];
            if (cur == 5)
            {
                fives++;
            }
            else if (cur == 10)
            {
                if (fives > 0)
                {
                    fives--;
                    tens++;
                }
                else
                {
                    isPossible = false;
                    break;
                }
            }
            else
            {
                if (tens > 0)
                {
                    tens--;
                }
                else if (fives >= 2)
                {
                    fives -= 2;
                }
                else
                {
                    isPossible = false;
                    break;
                }
            }
        }

        if (isPossible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}