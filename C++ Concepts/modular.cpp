#include<iostream>
#include <stdio.h>

using namespace std;

int area(int length, int breadth){
	return length*breadth;
}

int peri(int length, int breadth){
	int p;
	p=2*(length+breadth);
	return p;
}

int main()
{
	int length=0, breadth=0;

	printf("Enter length and breadth");
	cin>>length>>breadth;

	int a=area(length, breadth);
	int perimeter=peri(length, breadth);
	
	printf("Area=%d\nPerimeter=%d\n",a,perimeter);
	return 0; 
}