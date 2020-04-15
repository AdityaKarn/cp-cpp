#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int t,n ; cin>>t;
    long long int sum;
    while(t--){
        cin>>n;
        long long int arr[n];

        for(int i =0; i<n; i++) cin>>arr[i];


        sort(arr,arr+n);

        sum =0;
        int j=0;

        for(int i= n-1; i>=0; i--){
            if((arr[i]-j)>0){
                sum = sum+ arr[i] - j;
                j++;
            }
            else break;

        }

        cout<<sum<<endl;
    }


    return 0;
}