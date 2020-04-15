#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, que, sizeOffArray, que1,que2,temp;

    cin>>n>>que;
    vector<int> vec[n];


    // making vector of arrays

    for(int i=0; i<n; i++){
        cin>>sizeOffArray;
        for(int j =0; j<sizeOffArray; j++)
        {
            cin>>temp;
            vec[i].push_back(temp);
        }

    }


// making queries

for(int k=0; k<que;k++){
    cin>>que1>>que2;
    cout<<vec[que1][que2]<<endl;
}

}

