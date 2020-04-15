#include <iostream>

using namespace std;

int main(){
    int a[2][2], m[2][2]; 
    for(int i = 0; i<2; i++){
        for(int j =0; j<2; j++){
            cin>>a[i][j];
        }
    }


    for(int i = 0; i< 2; i++){
        for(int j = 0; j<2; j++){
            m[i][j]=0;
            for(int k = 0; k<2;k++){
                m[i][j] += a[i][k] *  a[k][j];

            }

        }
    }

    for(int i = 0; i<2; i++){
        for(int j =0; j<2; j++){
            cout<<m[i][j]<<endl;
        }
    }



    return 0;
}