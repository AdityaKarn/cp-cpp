#include<iostream>
using namespace std;


int main() {
	int arrsize, i, a[10005], j, k;
	cout << " enter the size of array" << endl;
	cin >> arrsize;

	for (i = 0;i < arrsize;i++) {
		cout << "enter array at position " << i;
		cin >> a[i];
		cout << endl;

	}

	for (i = 0;i < arrsize;i++) {
		for (j = i;j < arrsize;j++) {
			for (k = i;k <= j;k++) {
				cout << a[k]<<" ";
			}
			cout << endl;
		}
	}
	return 0;
}
