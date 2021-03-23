#include<iostream>
using namespace std;
int main() {
	int A[5] = { 2,3,4,5,6 };
	int *p;

	p = new int[5];
	p[0] = 1;
	p[1] = 2;
	p[2] = 3;
	p[3] = 4;
	p[4] = 5;

	for (int i = 0; i < 5; i++) {
		printf("%d ", A[i]);
	}
	cout << endl;
	for (int i = 0; i < 5; i++) {
		printf("%d ", p[i]);
	}

	return 0;
}