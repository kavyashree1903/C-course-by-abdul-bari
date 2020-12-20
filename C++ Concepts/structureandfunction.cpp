#include<iostream>
#include <stdio.h>

using namespace std;

struct Rectangle{
	int length;
	int breadth;
};

void initialise(struct Rectangle *r, int l, int b){
	r->length=l;
	r->breadth=b;
}

int area(struct Rectangle r1){
	return r1.length*r1.breadth;
}

int peri(struct Rectangle r1){
	int p;
	p=2*(r1.length+r1.breadth);
	return p;
}

int main()
{
	Rectangle r={0, 0};
	int l,b;
	printf("Enter length and breadth");
	cin>>l>>b;
	
	initialise(&r, l, b);
	int a=area(r);
	int perimeter=peri(r);
	
	printf("Area=%d\nPerimeter=%d\n",a,perimeter);
	return 0; 
}