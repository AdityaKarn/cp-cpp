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
#define INF 1000000000


using namespace std;



int main(){
    int t, n, q, x1, x2, y;
    int a[100001];
    cin>>t;

    while(t--){
        cin>>n>>q;

        for(int i = 1; i<=n; i++){
            cin>>a[i];
        }
        
        int count = 0;
        for(int i = 0; i<q; i++){
            cin>>x1>>x2>>y;
            count =0;
            for(int j = 1; j<=n; j++){

                if(y>=a[j] && y<= a[j+1] || y<=a[j] && y>=a[j+1]){

                    if(x1<=j && x2>=j+1){
                            count++;
                    } 
                }
            }
            cout<<count<<endl;
        }        
        
    }


    return 0;
}