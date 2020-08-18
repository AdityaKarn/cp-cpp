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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    string s;
    while (t--)
    {
        vector<int> v;

        cin >> s;

        int oneContinuous = 0;
        int count = 0;
        for (char ch : s)
        {

            if (ch == '1' && oneContinuous == 0)
            {
                oneContinuous = 1;
                count++;
            }
            else if (ch == '1' && oneContinuous == 1)
            {
                count++;
            }
            else if (ch == '0' && oneContinuous == 1)
            {
                v.push_back(count);
                count = 0;
            }
        }
        v.push_back(count);

        sort(v.begin(), v.end(), greater<int>());

        int res = 0;

        for (int i = 0; i < v.size(); i = i + 2)
        {
            res += v[i];
        }
        cout << res << "\n";
    }
    return 0;
}