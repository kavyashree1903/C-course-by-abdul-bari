#include<iostream>

int fact(int n) {
	int i;
	int fact=1;
	for (i = 1; i <= n; i++) {
		fact = fact * i;
	}
	return fact;
}

int main() {
	int r;
	r = fact(5);
	printf("%d \n", r);
	return 0;
}