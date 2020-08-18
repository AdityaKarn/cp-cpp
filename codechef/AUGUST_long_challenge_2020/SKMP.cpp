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

int isInc(string str) {

    for (int i = 1; i<str.length(); i++) {
        if (str[i]<str[i-1]) {
            //decreasing
            return 0;
        }
    }
    return 1;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;

    while (t--) {
        string s, p;
        cin>>s>>p;


        sort(s.begin(), s.end());

        // deleting p from s
        int i = 0;
        while (i< p.length()) {
            int idx;
            char ch = p[i];

            int l = 0, r= s.length()-1;
            int mid = (l+r)/2;

            while (l<=r) {

                mid = (l+r)/2;

                if (s[mid]==ch) {
                    idx = mid;
                    break;
                }

                else if (ch > s[mid]) {
                    l = mid+1;
                }
                else {
                    r = mid-1;
                }

            }
            s.erase(s.begin() + idx);

            i++;
        }

        //  merging the two strings

        if (p[0]< s[0]) {
            string res;
            res.append(p);
            res.append(s);
            cout<<res<<"\n";
        }
        else if (p[0]>s[s.length()-1]) {
            string res;
            res.append(s);
            res.append(p);
            cout<<res<<"\0";
        }
        else {

            if (isInc(p)) {
                int idx=0;
                while (p[0] >= s[idx] && idx< s.length()-1) {
                    idx++;
                }

                int start_len = idx-1;
                int last_len = s.length() - start_len;

                string res;
                res.append(s.substr(0, start_len+1));
                res.append(p);
                res.append(s.substr(start_len+1, last_len));
                cout<<res<<"\n";
            }



            else {
                int idx=0;
                while (p[0] > s[idx] && idx< s.length()-1) {
                    idx++;
                }

                int start_len = idx-1;
                int last_len = s.length() - start_len;

                string res;
                res.append(s.substr(0, start_len+1));
                res.append(p);
                res.append(s.substr(start_len+1, last_len));
                cout<<res<<"\n";
            }
        }


    }

    return 0;
}