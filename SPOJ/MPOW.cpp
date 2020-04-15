#include<iostream>

#define N 101

using namespace std;

int A[N][N], I[N][N];

void mult(int A[][N], int B[][N], int dim){
    int C[dim][dim];

    for(int i=0; i< dim; i++){
        for(int j =0; j< dim; j++){
            C[i][j]=0;
            for(int k=0; k<dim;k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for(int i=0; i< dim; i++){
        for(int j =0; j< dim; j++){
            A[i][j]= C[i][j];
        }
    }   
}

void power(int A[][N], int dim, int x){
    for(int i =0; i<dim;i++){
        for(int j=0; j< dim; j++){
            i==j? I[i][j]=1: I[i][j]=0;
        }  

    }



    while(x){
        if(x%2){
            mult(I,A,dim); x--;
        }

        else{
            mult(A,A, dim); x /= 2;
        }
    }

    for(int i =0; i<dim;i++){
        for(int j=0; j< dim; j++){
            A[i][j] = I[i][j];
        }  
    }
    
}

int main(){
    int t, n, pow;
    cin>>t;

    while(t--){
        cin>>n; cin>>pow;
        for(int i =0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>A[i][j];
            }
        }
        power(A, n, pow);

        for(int i =0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<A[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}