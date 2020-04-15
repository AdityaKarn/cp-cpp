#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,temp,i;
    temp=0;
    vector<int> vec;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>temp;
        vec.push_back(temp);
    }

    for(i=0;i<n;i++){
        cout<<vec.back()<<" ";
        vec.pop_back();
    }
    return 0;
}
