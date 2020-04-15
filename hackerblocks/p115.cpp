#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

int main() {
    vector<int> arr;
	int t, n,a;
	cin>>t;
	while(t--){
		cin>>a;
		for(int i =0; i<a; i++){
			cin>>n;
            cout<<*(arr.end())<<"\t";
            if(n== *(arr.end())){
                continue;
            }
            else{
                arr.push_back(n);
            }
		}

        vector<int>::iterator i;

        for(i = arr.begin(); i< arr.end(); i++){
            cout<<*(i);
        }

        arr.clear();
	}
	return 0;
}