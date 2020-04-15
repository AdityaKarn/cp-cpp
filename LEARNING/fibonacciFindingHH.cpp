#include<iostream>

using namespace std;

int A[1][2], B[1][2];
int TM[2][2] = { {0,1},{1,1} };

void mult(int A[][2], int B[][2]){
    int C[1][2];

    for(int i =0; i<1; i++){
        for(int j=0; j<2; j++){
            C[i][j]=0;
            for(int k=0; k<2; k++){
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }

    for(int i =0; i<1; i++){
        for(int j=0; j<2; j++){
            B[i][j] = C[i][j];
        }
    }
}

void powerM(int A[][2], int n){
    
}

int main(){


    for(int i=0;i<1;i++){
        for (int j = 0; j < 2; i++)
        {
            cin>>A[i][j];
        }   
    }   

    int n; cin>>n;
    powerM(A,n);
    
    for(int i=0;i<1;i++){
        for (int j = 0; j < 2; i++)
        {
            cout<<B[i][j];
        }   
    }   

}