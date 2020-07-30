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

using namespace std;

lli powerOFTwo(lli n)
{
    lli res = 0;
    while (n % 2 == 0)
    {
        res++;
        n /= 2;
    }
    return res;
}

int main()
{
    int t;
    lli ts;
    cin >> t;

    while (t--)
    {
        cin >> ts;

        set<lli> twos;
        lli powTwo = powerOFTwo(ts);
        powTwo++;

        //first two loops
        if ((1 << powTwo) < ts)
        {
            lli currentPower = (1 << powTwo);

            for (int i = 1;; i++)
            {
                lli number = currentPower * i;

                if (number > ts)
                {
                    break;
                }

                twos.insert(number);
            }
            powTwo++;
        }
        //first two loops
        if ((1 << powTwo) < ts)
        {
            lli currentPower = (1 << powTwo);

            for (int i = 1;; i++)
            {
                lli number = currentPower * i;

                if (number > ts)
                {
                    break;
                }

                twos.insert(number);
            }
            powTwo++;
        }

        while ((1 << powTwo) < ts)
        {
            lli currentPower = (1 << powTwo);

            for (int i = 1;; i += 2)
            {
                lli number = currentPower * i;

                if (number > ts)
                {
                    break;
                }

                twos.insert(number);
            }
            powTwo++;
        }
        cout << twos.size() << "\n";
        twos.clear();
    }
    return 0;
}