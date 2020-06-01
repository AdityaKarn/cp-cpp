#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
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
#define N 16
using namespace std;

int a[N];
int b[1 << N];
int c[1 << N];

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;

        int m = 1 << n;

        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }

        sort(b, b + m);

        multiset<int> s;
        int fptr = 0, ptr = 0;

        for (int i = 1; i < m; i++)
        {
            int expected = -1;

            if (!s.empty())
            {
                expected = *s.begin();
            }

            if (expected == b[i])
            {
                s.erase(s.begin());
            }
            else
            {
                a[fptr] = b[i];
                int tptr = ptr;

                for (int j = 0; j < tptr; j++)
                {
                    c[ptr] = c[j] + a[fptr];
                    s.insert(c[ptr]);
                    ptr++;
                }

                c[ptr++] = a[fptr];
                fptr++;
            }
        }

        for (int i = 0; i < fptr; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}