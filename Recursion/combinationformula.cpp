#include<iostream>

int C(int n, int r) {
	if ( n==r || r==0) {
		return 1;
	}
	else {
		return C(n - 1, r - 1) + C(n - 1, r);
	}
} //can be done by normal factorial method as well
int main() {
	printf("%d \n", C(4,2));
	return 0;
}