#include<iostream>
using namespace std;
int main(){
	// int A[5]={2,4,6,8,10};
	// int *p;
	// p=A; //&A[0]
	// printf("%d",p); //this will print the address which would be same as &a
	// printf("%d",*p); //Derefrencing a pointer
	// for(int i=0;i<5;i++){
	// 	cout<<p[i]<<endl;
	// }
	int *p;
	p=new int[5]; //accessing heap memory 
	p[0]=10;
	p[1]=15;
	p[2]=14;
	p[3]=21;
	p[4]=31;
	for(int i=0;i<5;i++){
		cout<<p[i]<<endl;
	}
	delete [] p; //Preferred in large programs
	return 0;
}