//to find consequetive 10 digit no. in e

#include<iostream>
#include<math.h>

using namespace std;

bool checkPrime(long int p){
    int upperlimit = sqrt(p) + 1;
    for(int i = 2; i<upperlimit; i++){
        if(p%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    
    string str1 = "7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274274663919320030599218174135966290435729003342952605956307381323286279434" ;



    return 0;
}