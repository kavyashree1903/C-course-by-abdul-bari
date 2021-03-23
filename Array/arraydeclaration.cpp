#include<iostream>
using namespace std;
int main() {
	int A[5];
	int B[5] = { 1,2,3,4,5 };
	int C[10] = { 2,4,6 };
	int D[5] = { 0 };
	int E[] = { 1,2,3,4,5,6 };
	for (int i = 0 ; i < 5 ; i++) {
		printf("%d ", A[i]);
	}
	cout << endl;
	for (int j = 0; j < 5; j++) {
		printf("%d ", B[j]);
	}
	cout << endl;
	for (int k = 0; k < 10; k++) {
		printf("%d ", C[k]);
	}
	cout << endl;
	for (int x = 0; x < 5; x++) {
		printf("%d ", D[x]);
	}
	cout << endl;
	cout << sizeof(E); //24 --> 4*6
	return 0;
}