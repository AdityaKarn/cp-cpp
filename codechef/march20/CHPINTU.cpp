#include<iostream>
#include<vector>
#include<algorithm>

#define REP(i,n) for (int i = 1; i <= n; i++)

#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000


using namespace std;

int F[51];
int P[51];
int freq[51];

int main(){
    int t,n,m, curr_cost, curr, minsum = INF;

    cin>>t;

    while(t--){
        cin>>n>>m;

        for(int i = 0; i<n; i++) P[i]=0;

        for(int i= 0; i<n; i++){
            cin>>F[i];
            freq[i] = 0;
        }

        for(int i = 0; i<n; i++){
            cin>>curr_cost;
            curr = F[i];

            P[curr] = P[curr] + curr_cost; 
            freq[curr]++;
        }
        
        for(int i = 1; i<=m; i++){
            
            if(freq[i]>0){
                minsum = min(minsum, P[i]);
            }
        }

        cout<<minsum<<endl;
     
    }


    return 0;
}