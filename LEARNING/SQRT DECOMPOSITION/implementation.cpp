#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

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
int n, bsize;
int b[100];
int arr[1000];

int getMinSQRT(int l, int r){
    int bL = l/bsize; int rL = r/bsize;
    int mn = INF;

    if(bL == rL) {
        for(int i = l; i<= r; i++){
            int mn = min(mn, arr[i]);
        }
    }
    else{
        for(int i = l; i< bsize*(bL+1); i++){
            mn = min(mn, arr[i]);
        }
        for(int i = bL+1; i<rL; i++){
            mn = min(mn, b[i]);
        }
        for(int i = bsize*rL; i<=r; i++){
            mn = min(mn, arr[i]);
        }
    }

    return mn;

}


int main(){

    cin>>n;
    bsize = sqrt(n);
    int bsizeLim = bsize - 1;
    
    int minB = INF;
    int j =0;

    for(int i =0; i<n; i++){
        if(i%bsize == 0) minB = INF;
        cin>>arr[i];
        minB = min(minB, arr[i]);


        if(i%bsize == bsizeLim) b[j++] = minB;
    }

    int left, right;

    cin>>left>>right;

    cout<<getMinSQRT(left, right);



    return 0;
}