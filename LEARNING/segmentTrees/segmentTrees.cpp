//For minimum query

#include<iostream>
#include<algorithm>

using namespace std;


int arr[] = {1,2,-3};

int st[10];


void buildTree(int si, int ss, int se){
    if(ss==se) st[si]= arr[ss];

    int mid = (ss+se)/2;

    buildTree(2*si, ss, mid);
    buildTree(2*si +1, mid+1, se);

    st[si] = min(st[si*2], st[si*2+1]);
}

int main(){
    buildTree(1,0,2);

    cout<<st[1];
    
}