#include<iostream>
double e(int x, int n) { // return type should be double
	static double p = 1, f = 1;
	double r;
	if (n == 0) {
		return 1;
	}
	else {
		r = e(x, n - 1);
		p = p * x;
		f = f * n;
		return r + (p / f);
	}
}
int main() {
	printf("%lf \n", e(1, 10)); // take more terms
	return 0;
}