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

int main()
{

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        n--;

        int chessboard[9][9];

        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
                chessboard[i][j] = -1;
        }
        int count = 0;

        // X = -1
        int currRow = 7;
        while (true)
        {

            for (int j = 1; j <= 9 - currRow; j++)
            {

                if (count < n)
                {
                    chessboard[currRow][j] = 0;
                    count++;
                }
            }
            if (count < n)
                for (int j = currRow + 1; j <= 8; j++)
                {
                    if (count < n)
                    {
                        chessboard[j][9 - currRow] = 0;
                        count++;
                    }
                }

            if (count >= n)
            {
                break;
            }
            currRow--;
        }

        for (int i = 1; i <= 8; i++)
        {
            for (int j = 8; j >= 1; j--)
            {
                if (i == 8 && j == 1)
                {
                    cout << "O";
                }
                else if (chessboard[i][j] == 0)
                {
                    cout << ".";
                }
                else if (chessboard[i][j] == -1)
                {
                    cout << "X";
                }
            }
            cout << "\n";
        }
    }
}