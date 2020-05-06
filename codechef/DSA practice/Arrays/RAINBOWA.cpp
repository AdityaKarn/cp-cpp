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

int freq[8];
int A[102];

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {

        vector<pair<int, int>> cnt;
        bool rainbow = true;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        int count = 1, which = A[0];

        for (int i = 1; i < n; i++)
        {
            if (A[i] == A[i - 1])
            {
                count++;
            }
            else
            {
                cnt.push_back({which, count});
                count = 1;
                which = A[i];
            }
        }

        if (count > 0)
        {
            cnt.push_back({which, count});
        }

        if (cnt.size() == 13)
        {
            for (int i = 0; i < 13; i++)
            {
                if (cnt[i] != cnt[13 - i - 1])
                {
                    rainbow = false;
                }
                if (i < 7 && cnt[i].first != i + 1)
                {
                    rainbow = false;
                }
            }
        }
        else
        {
            rainbow = false;
        }

        if (rainbow)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}