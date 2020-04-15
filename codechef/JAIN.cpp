#include<iostream>
#include<string>

using namespace std;



int main(){
    long long int F[32];
    int t, n, mask; cin>>t; 
    string s;

    while(t--){
        cin>>n;

        for(int i=0; i<32; i++) F[i]=0;

        for(int i =0; i< n; i++){
            cin>>s;
            mask =0;

            for(char ch: s){
                if(ch=='a') mask = mask | (1<<0);
                if(ch=='e') mask = mask | (1<<1);
                if(ch=='i') mask = mask | (1<<2);
                if(ch=='o') mask = mask | (1<<3);
                if(ch=='u') mask = mask | (1<<4);
            }

            F[mask]++;
        }

        long long int res = 0;

        for(int i =0; i< 32; i++){
            for(int j =i+1; j< 32; j++){
                if((i|j)==31){
                    res = res + (F[i]*F[j]);
                }
            }
        }

        res = res + (F[31]*(F[31]-1))/2;


        cout<<res<<endl;

    }

    return 0;
}