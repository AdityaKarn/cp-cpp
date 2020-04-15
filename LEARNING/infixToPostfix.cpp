#include<iostream>

using namespace std;

int prec(char c){
    if(c=='^') return 3;
    else if(c=='/'||c=='*') return 2;
    else if(c=='+'||c=='-') return 1;
    else return -1;
}

int main(){

    


    return 0;
}