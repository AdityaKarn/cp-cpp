#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<map>
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

        int cur;
        map<int, int> mp;
        int maxfreq=0;

        for (int i = 0; i<n; i++) {
            cin>>cur;
            mp[cur]++;

        }

        for (auto x: mp) {
            (x.second>1)?maxfreq+=x.second:maxfreq+=0;
        }

        // if maxfreq is less than k, optimal is getting everyone at a single table. 
        //if not, cost will inc by +k - maxfreq
        if (maxfreq<k) {
            cout<<k+maxfreq<<"\n";
            continue;
        }

        //else we need to minimize by getting another table one by one for a single member for each family;

        int currRes=k+maxfreq, newRes;
        int tablestillnow = k;
        while (true) {

            int firstTableCost=0;
            // cost of first table
            for (auto x: mp) {

                if (x.second > 2) {
                    firstTableCost += x.second-1;
                    mp[x.first]--;
                }
            }


            cout<<"current table cost + first table cost + k"<<tablestillnow<<" "<<firstTableCost<<" "<<k<<"\n";

            //getting total cost in this iteratiom
            newRes = tablestillnow + firstTableCost + k;

            //storing the tablw increase
            tablestillnow += k;

            if (newRes<=currRes) {
                currRes = newRes;
            }
            else {
                break;
            }

            // if (newRes == 0) {
            //     break;
            // }
        }

        cout<<currRes<<"\n";

    }

    return 0;
}