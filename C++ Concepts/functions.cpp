#include<iostream>
using namespace std;

int add(int a, int b){
	int c;
	c=a+b;
	return c;
}
int main(){
	int x=122;
	int y=34;
	int z;
	z=add(x,y);
	printf("The sum is %d\n",z );
}