#include <stdio.h>
#include <stdlib.h>

void main(){

    char a[100];
    int i = 0,j =0, k=0, flag =0;

    gets(a);

    while(a[i] != '\0'){
        i++;
        j++;
    }

    printf("%d", j);



    for(i=0; i< j/2; i++){
        if(a[i]!=a[--j]){
            flag = 1;
            break;
        }
    }

    if(flag==0){
        printf("yes");
    }
    else{
        printf("no");
    }
}