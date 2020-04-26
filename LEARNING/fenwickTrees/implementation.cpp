//brings sum of arr[0]...arr[i] in OlogN

#include <iostream> 

using namespace std; 




void add(int BITree[], int n, int idx, int val){

    for(++idx; idx<n; idx += idx&(-idx)){
        BITree[idx] += val;
    }
}

void rangeAdd(int BITree[], int n, int a,int b, int val){
    add(BITree, n, a, val);
    add(BITree, n, b+1, -val);
}

int PointQuery(int BITree[], int idx){
    int res= 0;

    for(++idx; idx>0; idx -= idx&(-idx)){
        res += BITree[idx];
    }

    return res;
}

int getSum(int BITree[], int idx){
    int res= 0;

    idx = idx + 1;

    while(idx>0){
        res += BITree[idx];

        idx -= idx&(-idx);
    }

    return res;
}

void updateBIT(int BITree[], int n, int idx, int value){

    idx = idx+1;

    while(idx<=n){
        BITree[idx] += value;

        idx += idx & (-idx);
    }

}


int *constructFenwick(int a[], int n){

    int *BITree = new int[n+1];

    for(int i =0; i<n; i++){
        BITree[i] = 0;
    }

    for(int i = 0; i<n; i++){
        updateBIT(BITree, n, i, a[i]);
    }

    return BITree;
}

int *emptyFenwick(int n){
    int *BITree = new int[n+1];

    for(int i =0; i<n; i++){
        BITree[i] = 0;
    }

    return BITree;

}

int main(){
    int arr[] = {1,2,3,4,-1,5,6};

    int size = sizeof(arr)/sizeof(arr[0]);

    int *BIT = constructFenwick(arr, size);

    int *B1= emptyFenwick(size);

    cout<<endl;


    for(int i = 0; i<size; i++){
        cout<<getSum(BIT,i)<<" ";
    }
    cout<<endl;

    rangeAdd(BIT, size, 2,6, 2);

    for(int i = 0; i<size; i++){
        cout<<PointQuery(BIT, i)<<" ";
    }
    

    return 0;
}