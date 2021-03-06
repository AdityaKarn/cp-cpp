#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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

int mat[51][51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    string in, on;
    cin >> t;

    while (t--)
    {
        cin >> n;

        cin >> in;
        cin >> on;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    mat[i][j] = 1;
                else
                    mat[i][j] = -1;
            }
        }

        for (int i = 0; i < n; i++)
        {

            if (in[i] == 'Y')
            {
                for (int j = i + 1; j < n; j++)
                {
                    mat[j][i] = 1;
                }
            }
            else
            {
                for (int j = 0; j < n; j++)
                {
                    if (i != j)
                        mat[j][i] = 0;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (on[i] == 'N')
            {
                for (int j = 0; j < n; j++)
                {
                    if (i != j)
                    {
                        mat[i][j] = 0;
                    }
                }
            }
            else
            {
                int temp = 1;
                for (int j = 0; j < n; j++)
                {
                    if (mat[i][j] == 0)
                    {
                        temp = 0;
                    }
                    mat[i][j] = temp;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << mat[i][j];
            }
            cout << "\n";
        }
    }
}