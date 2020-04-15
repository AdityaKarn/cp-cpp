#include<iostream>
using namespace std;

int countset(int a) {
	int rem, bin, i;
	bin = 0;
	rem = 0;
	i = 1;
	while (a > 0) {
		if (a & 1) {
			rem = 1;
		}
		else {
			rem = 0;
		}
		bin += rem * i;
		i *= 10;
		a= a >> 1;
	}
	cout << bin;
	return 0;
}


int main() {
	int a;
	cin >> a;
	countset(a);
	return 0;
}
