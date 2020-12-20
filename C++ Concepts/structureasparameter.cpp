#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Rectangle{
	int length;
	int breadth;
};

void fun(struct Rectangle *p){
 p->length=20;
 cout<<"length "<<p->length<<endl;
 cout<<"breadth "<<p->breadth<<endl;

}

int main(){
	struct Rectangle r={10,5};
	fun(&r);
	return 0;
}
