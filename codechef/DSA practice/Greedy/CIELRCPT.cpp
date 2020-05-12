#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
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

int Menu[12];

int main()
{
    for (int i = 0; i <= 11; i++)
    {
        Menu[i] = pow(2, i);
    }

    int t, p;
    cin >> t;

    while (t--)
    {
        cin >> p;
        int j = 11;
        lli count = 0;
        while (p)
        {

            if (p - Menu[j] >= 0)
            {
                count++;
                p -= Menu[j];
            }
            else
            {
                j--;
            }
        }

        cout << count << endl;
    }

    return 0;
}