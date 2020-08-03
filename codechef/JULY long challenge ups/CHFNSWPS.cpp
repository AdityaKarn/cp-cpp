#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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
        int checksum = 0;

        int min_element = 1e9;
        cin >> n;
        map<int, int> mpa, mpb;
        int curr;

        for (int i = 0; i < n; i++)
        {
            cin >> curr;
            checksum ^= curr;
            mpa[curr]++;
            min_element = min(min_element, curr);
        }

        for (int i = 0; i < n; i++)
        {
            cin >> curr;
            mpb[curr]++;
            checksum ^= curr;
            min_element = min(min_element, curr);
        }

        if (checksum)
        {
            cout << "-1\n";
            continue;
        }

        vector<int> A, B;

        for (auto a : mpa)
        {
            int ele = a.first;
            int freq = a.second;

            if (mpb.find(ele) != mpb.end())
            {
                int dx = min(freq, mpb[ele]);
                mpa[ele] -= dx;
                mpb[ele] -= dx;
            }
        }

        //initialising A and B
        for (auto p : mpa)
        {
            int ele = p.first;
            int freq = p.second;

            for (int i = 0; i < freq / 2; i++)
            {
                A.push_back(ele);
            }
        }
        for (auto p : mpb)
        {
            int ele = p.first;
            int freq = p.second;

            for (int i = 0; i < freq / 2; i++)
            {
                B.push_back(ele);
            }
        }

        reverse(B.begin(), B.end());

        lli res = 0;
        for (int i = 0; i < A.size(); i++)
        {
            res += min(2 * min_element, min(A[i], B[i]));
        }

        cout << res << "\n";
    }

    return 0;
}
