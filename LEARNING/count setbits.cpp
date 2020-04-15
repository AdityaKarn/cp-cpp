#include<iostream>
using namespace std;

int countset(int a) {
	int setbit, i;
	setbit = 0;
	i = 1;
	while (a > 0) {
		if (a & 1) {
			setbit++;
		}



		a = a >> 1;

	}

	cout << setbit;
	return 0;
}


int main() {
	int a;
	cin >> a;
	countset(a);
	return 0;
}
