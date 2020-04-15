#include<iostream>

using namespace std;

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n){
    int min_index;
    for(int i =0; i< n; i++){
        min_index = i;
        for(int j=i+1; j<n; j++){
            if(arr[min_index]>arr[j]){
                swap(&arr[min_index], &arr[j]);
            }
        }
    }
}
void bubbleSort(int arr[], int n){


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i]<arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
}
void insertionSort(int arr[], int n){
    int key, j;
    for(int i =1; i< n; i++){
        key = arr[i];
        j= i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1]= arr[j];
            j--;

        }
        arr[j+1]= key;
    }

}

void printarr(int arr[], int n){

    

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

    int arr[] = {0, 5 ,1,4,6,7,3,10,2};
    int n = sizeof(arr)/sizeof(arr[0]);
   // bubbleSort(arr, n);
   // selectionSort(arr,n);
   insertionSort(arr, n);
    printarr(arr,n);

    return 0;
}