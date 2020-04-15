#include<iostream>
#include<algorithm>

using namespace std;


void xswap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){

    int pivot = arr[high]; //pivot element

    int i = low-1; // first pointer (yellow)

    for(int j = low; j< high-1; j++){
        if(arr[j]<pivot){
            i++;
            xswap(&arr[i], &arr[j]);
        }
    } 
    xswap(&arr[i+1], &arr[high]); //putting pivot into its place
    return (i+1);
}





// partioning strategy 1

int quicksort(int arr[], int l, int r){
    
    if(l<r){
    int pi = partition(arr, l, r);

    quicksort(arr,l,pi-1);
    quicksort(arr,pi+1,r);
    }
}

void printArr(int arr[], int l, int r){

    for(int i = l; i<r; i++){
        cout<<arr[i];
    }
}




int main(){
    int a[] = {5,7,2,9,1,4,3,4,7};
    int n = sizeof(a)/sizeof(a[0]);
    quicksort(a,0,n-1);
    printArr(a,0,n-1);
    return 0;
}