#include <iostream>
using namespace std;

void swap(int *x, int *y){ //(int &x, int &y) --> for reference
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

int main(){
	int a=10;
	int b=20;
	swap(&a,&b);
	cout<<"a is "<<a<<endl;
	cout<<"b is "<<b<<endl;
	return 0;
}