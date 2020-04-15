#include <iostream>
#include <algorithm>
using namespace std;

int main(){
   int n, Ssum, Bsum;
   Ssum = 0;
   Bsum = 0;
   cin>>n;

   int arr[n];

   for(int i= 0; i< n; i++){
       cin>>arr[i];
       Ssum+=arr[i];
   }


   sort(arr, arr+n);

    int j=n-1;

    for(j=n-1; j>0; j--){
        Bsum += arr[j];
        Ssum -= arr[j];

        if(Bsum > Ssum){
            break;
        }

    }
    
    cout<< n-j;
    return 0;
}