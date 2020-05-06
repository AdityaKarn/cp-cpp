#include <iostream>
#include <cmath>

#define lli long long int
using namespace std;

lli turnOffLeft(lli n)
{
    lli x = log2(n);

    lli res = n;

    res &= ~(1 << x);

    return res;
}

int main()
{

    int t, maxC = 0;
    lli x, y, l, r;
    cin >> t;

    while (t--)
    {
        cin >> x >> y >> l >> r;
        lli res;

        if (x == 0 || y == 0)
        {
            res = 0;
        }
        else
        {
            res = x | y;
        }

        if (res < l || res > r)
        {
            // for (int i = l; i <= r; i++)
            // {
            //     int c = (x & i) * (y & i);

            //     if (c > maxC)
            //     {
            //         maxC = c;
            //         res = i;
            //     }
            // }

            while (true)
            {
                if (x > y)
                {
                    x = turnOffLeft(x);
                }
                else
                {
                    y = turnOffLeft(y);
                }

                res = x | y;

                if (res >= l && res <= r)
                {
                    break;
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}