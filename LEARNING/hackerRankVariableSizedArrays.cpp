#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, que, sizeOffArray, que1,que2,temp,count;
    vector<int> arr,arr1,arr2;

    cin>>n>>que;

// making arrays
    for(int i=0;i<n;i++){
        cin>>sizeOffArray;
        arr1.push_back(sizeOffArray);
        for(int j=0;j<sizeOffArray;j++){
            cin>>temp;
            arr.push_back(temp);
        }
    }

//making queries
    for(int k=0;k<que;k++){
        cin>>que1>>que2;
        count=0;
        for(int l=0;l<que1;l++){
            count+= arr1[l];
        }
        temp = count + que2;
        arr2.push_back(temp);
    }

    for(int k=0;k<que;k++){
        cout<<arr[arr2[k]];
    }
    
    return 0;
}

// see error