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
    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
        {
            break;
        }
        int currResult;
        int min_height = INF, max_height = 0, UpOrDown = 0, prevOrDown = 0, iteration = 1, prev; //up = 1, down = -1

        int curr;
        cin >> curr;

        min_height = max_height = curr;
        prev = curr;
        int res = 0;

        for (int i = 1; i < n; i++)
        {
            cin >> curr;

            curr >= prev ? UpOrDown = 1 : UpOrDown = -1;

            if (UpOrDown == 1)
            {

                min_height = min(min_height, prev);
            }
            else
            {
                max_height = max(min_height, prev);
            }

            if (UpOrDown != prevOrDown)
            {
                //shape badla, calculate result

                if (UpOrDown == 1)
                {
                    currResult = min_height * iteration;
                }
                else
                {
                    currResult = min_height * iteration;
                }
                cout << currResult << " c ";
                res = max(res, currResult);

                max_height = min_height = curr;
                iteration = 1;
            }
            else if (UpOrDown == prevOrDown && UpOrDown == 1)
            {
                // add height
                iteration++;
            }
            else if (UpOrDown == prevOrDown && UpOrDown == -1)
            {
                //add height
                iteration++;
            }

            prev = curr;
            prevOrDown = UpOrDown;

            if (i == n - 1)
            {
                if (UpOrDown == 1)
                {
                    currResult = min_height * iteration;
                }
                else
                {
                    currResult = min_height * iteration;
                }
                cout << currResult << " c ";
            }
        }

        cout << res << endl;
    }

    return 0;
}