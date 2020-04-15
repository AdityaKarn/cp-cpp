#include<iostream>
using namespace std;


int main() {
	int arrsize, i, a[10005], j, k;
	long long int sum, maxsum;
	sum = 0;
	maxsum=0;

	cout << " enter the size of array" << endl;
	cin >> arrsize;

	for (i = 0;i < arrsize;i++) {
		cout << "enter array at position " << i;
		cin >> a[i];
		cout << endl;

	}

	for (i = 0;i < arrsize;i++) {
		for (j = i;j < arrsize;j++) {
			sum = 0;
			for (k = i;k <= j;k++) {
				sum += a[k];

			}
		if(sum>maxsum){
			maxsum=sum;
		}
		}
	}
	cout<<maxsum;
	return 0;


}
