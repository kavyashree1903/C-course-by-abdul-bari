#include<iostream>

int sum(int n) {
	int i;
	int sum=0;
	for (i = 0; i <= n; i++) {
		sum = sum + i;
	}
	return sum;
}

int main() {
	int r;
	r = sum(5);
	printf("%d \n", r);
	return 0;
}