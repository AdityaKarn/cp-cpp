#include<iostream>

using namespace std;

int countdigits(int n){
    int size=0;
    while(n){
        size++;
        n= n/10;
    }
    return size;
}

int reverseNum(int n){
    int temp = n;
    int rem, rev=0;
    while(temp){
        rev = (rev*10) + temp%10;
        temp /= 10;
    }
    return rev;
}

int main(){
    long int n;
    int curr, curr2;;
    cin>>n;

    int sizeOfNum = countdigits(n);
    
    int rev = reverseNum(n);

    while(sizeOfNum){
        curr = rev%10;
        rev /= 10;
        if(sizeOfNum>4){
            cout<<"OVERFLOW";       
        }

        else if(sizeOfNum==4){
            cout<<curr<<" thousand ";
        }

        else if(sizeOfNum==3){
            cout<<curr<<" hundred ";
        }
        else if(sizeOfNum==2){
            if(curr>3){
                cout<<curr<<"ty";
                curr = rev%10;
                rev /= 10;
                cout<<" "<<curr;
            }
            
        }


        
        sizeOfNum--;

    }

    return 0;
}