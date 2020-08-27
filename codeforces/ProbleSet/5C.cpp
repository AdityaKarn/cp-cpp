#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>

#define REP(i,n) for (int i = 1; i <= n; i++)

#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000


using namespace std;

int S[1000001], E[1000001], F[1000001];


int main(){
    string s;
    stack<int> stk;
    int mx = 0,l;

    cin>>s;

    for(int i = 0; i<s.size(); i++){
        char ch = s[i];

        if(ch == '('){
            stk.push(i);
        }
        else{

            if(stk.empty()){
                S[i] = E[i] = -1;
            }

            else{
                int idx = stk.top();
                stk.pop();

                S[i] = E[i] = idx;

                if(idx>0 && s[idx-1]==')' && S[idx-1]>=0){
                    E[i] = E[idx-1];
                }

                l = i - E[i] +1;
                F[l]++;

                mx = max(mx, l);
            }
        }
        
        
    }
    F[0] = 1;
    cout<<mx<<" "<<F[mx];
}