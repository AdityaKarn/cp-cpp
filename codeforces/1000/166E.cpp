#include<iostream>


using namespace std;
// current will stand for 0 A, 1B, 2C, 3D
long long int COUNT = 0;

void traverse(int current, int steps){

    int temp1, temp2, temp;
    if(steps==1 && current!=3){
        COUNT = (COUNT+1)%1000000007;
        
    }
    else if (steps==2){
        if(current ==0){
            traverse(1,steps-1);
            traverse(2,steps-1);
            
        }
        else if(current ==1){
            traverse(0,steps-1);
            traverse(2,steps-1);
        }
        else if(current ==2){
            traverse(1,steps-1);
            traverse(0,steps-1);
        }
        else{
            traverse(0,steps-1);
            traverse(1,steps-1);
            traverse(2,steps-1);
        }
    }
    else{
        if(current ==0){
            traverse(1,steps-1);
            traverse(2,steps-1);
            traverse(3, steps-1);
        }
        else if(current ==1){
            traverse(0,steps-1);
            traverse(2,steps-1);
            traverse(3, steps-1);
        }
        else if(current ==2){
            traverse(1,steps-1);
            traverse(0,steps-1);
            traverse(3, steps-1);
        }
        else{
            traverse(0,steps-1);
            traverse(1,steps-1);
            traverse(2,steps-1);
        }
    }
}

int main(){
    int n;
    cin>>n;
    if(n==1){
        cout<<"0";
    }else{
        traverse(3,n);
        cout<<COUNT;        
    }

    return 0;
}