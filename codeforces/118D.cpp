#include<iostream>


#define REP(i,n) for (int i = 1; i <= n; i++)

#define mod 100000000
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000


using namespace std;

int f_limit, h_limit;
lli dp[101][101][11][11];

int getBeauty( int f, int h, int k1, int k2){

    if((f+h)==0) return 1;
    int x =0,y=0;

    if(dp[f][h][k1][k2] != -1) return dp[f][h][k1][k2];

    //for f
    if(f>0 && k1 >0) x = getBeauty( f-1, h, k1-1, h_limit);



    //for h
    if(h>0 && k2>0) y = getBeauty( f, h-1, f_limit, k2-1);

    return dp[f][h][k1][k2] =  (x+y)%mod;
}


int main(){
    int t, n1, n2; t=1;

    while(t--){
        cin>>n1>>n2>>f_limit>>h_limit;

        for(int i=0; i<=n1; i++){
            for(int j = 0; j<=n2; j++){
                for(int k =0; k<=f_limit; k++){
                    for(int l = 0; l<= h_limit; l++){
                        dp[i][j][k][l] = -1;
                    }
                }
            }
        }

        int ans = getBeauty( n1, n2, f_limit, h_limit);

        cout<<ans<<endl;

    }


    return 0;
}