#include <iostream>
#include <cmath>
using namespace std;

int turnOffLeftMostSetBit(int n)
{
    int x = log2(n);

    int res = n;

    res &= ~(1 << x);
    return res;
}

int main()
{

    int t, x, y, l, r;
    cin >> t;

    while (t--)
    {
        cin >> x >> y >> l >> r;

        int res = x | y;

        if (res >= l && res <= r)
        {
            cout << res << endl;
        }
        else
        {
            while (true)
            {
                if (x > y)
                {
                    x = turnOffLeftMostSetBit(x);
                    res = x | y;
                }
                else
                {
                    y = turnOffLeftMostSetBit(y);
                    res = x | y;
                }

                if (res >= l && res <= r)
                {
                    cout << res << endl;
                    break;
                }
            }
        }
    }

    return 0;
}