#include<stdio.h>
using namespace std;
struct Rectangle{
	int length; //4 bytes
	int breadth; //4 bytes
};
int main(){
	struct Rectangle r1={10,10};
	printf("%d\n",r1.length*r1.breadth );
	printf("%lu\n", sizeof(r1));
} 