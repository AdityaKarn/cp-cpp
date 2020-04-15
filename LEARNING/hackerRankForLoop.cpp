#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;


int max_of_four(int a, int b, int c, int d){
    int i,j,temp[5]={a,b,c,d};
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if (temp[i]<temp[j]){
                temp[i]= temp[i]^temp[j];
                temp[j]=temp[i]^temp[j];
                temp[i]=temp[i]^temp[j];
            }
        }
    }
    return temp[3];
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}

