#include<iostream>
using namespace std;
int main(){
	int a=10;
	int &r=a; //reference and must be intialised
	printf("%d",r);
	return 0;
}