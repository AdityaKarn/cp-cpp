#include<iostream>
#include<math.h>

#define REP(i,n) for(int i =0; i<n; i++)

using namespace std;


int factorial(int n) 
{ 
    // single line to find factorial 
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1); 
} 
  

int main(){

    long long int res;
    int t,x;
    cin>>t;

    while(t--){
        cin>>x;

        cout<<factorial(x)<<endl;
    }


    return 0;
}