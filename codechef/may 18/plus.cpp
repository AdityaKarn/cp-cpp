#include<iostream>
#include<climits>
using namespace std;

int main(){
    int T; cin>>T;
    for(int k = 0; k< T; k++){
        int n, m, sum;

        cin>>n>>m;
        int arr[n][m];
        for(int i = 0; i< n ; i++){
            for(int j=0; j< m; j++){
                cin>>arr[i][j];
            }
        }

        int maxplus = INT_MIN;
        for(int i =1; i< n-1; i++){
            for(int j = 1; j< m-1; j++){
                sum = arr[i][j]+ arr[i-1][j]+ arr[i+1][j]+ arr[i][j-1]+ arr[i][j+1];
                if(sum> maxplus){
                    maxplus = sum;
                } 
            }
        }

        cout<<maxplus;
        }
    
    return 0;
}