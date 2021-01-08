#include<iostream>
double e(int x, int n) { // return type should be double
	static double s=1;
	double r;
	if (n == 0) {
		return s;
	}
	else {
		s = 1 + x * s / n;
	}
	return e(x, n - 1);
}
int main() {
	printf("%lf \n", e(1, 10)); // take more terms
	return 0;
}