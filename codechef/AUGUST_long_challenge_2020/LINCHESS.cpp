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

    int t, n, k;
    cin>>t;

    while (t--) {

        cin>>n>>k;

        int minSteps = 1e9;
        int res = -1, temp;

        for (int i =0; i<n; i++) {
            cin>>temp;

            if (k%temp == 0) {
                int steps = k/temp;

                if (steps<minSteps) {
                    minSteps = steps;
                    res = temp;
                }
            }
        }

        cout<<res<<"\n";
    }
    return 0;
}