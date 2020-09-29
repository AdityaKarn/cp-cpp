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

void solveTestCases()
{
    int n;
    string s;
    cin >> n;
    cin >> s;

    int sz = s.size();

    int OdR = 0, EvB = 0;
    int totR, totB;

    totB = (sz / 2);
    totR = totB + (sz % 2);

    for (int i = 0; i < sz; i++)
    {
        if (i % 2 == 0)
        {
            //Raze
            if ((s[i] - '0') % 2 == 1)
            {
                OdR++;
            }
        }
        else
        {
            if ((s[i] - '0') % 2 == 0)
            {
                EvB++;
            }
        }
    }
    int EvR = totR - OdR;
    int OdB = totB - EvB;

    // cout << OdR << " " << EvR << " " << OdB << " " << EvB << " "
    //      << "\n";

    if (sz % 2 == 0)
    {
        //chck for B
        if (EvB >= OdB)
        {
            cout << "2\n";
        }
        else
        {
            cout << "1\n";
        }
    }
    else
    {
        if (OdR >= EvR)
        {
            cout << "1\n";
        }
        else
        {
            cout << "2\n";
        }
    }
}

int main()
{
    // IOS;
    int t;
    cin >> t;

    while (t--)
    {
        solveTestCases();
    }

    return 0;
}