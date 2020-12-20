#include <iostream>
using namespace std;
int main(){
	//int A[5];
	int A[10]={1,11,1231,33};
	//A[0]=12;
	//A[1]=2;
	//A[2]=34;
	// cout<<sizeof(A)<<endl;
	// cout<<A[1]<<endl;
	// printf("%d \n",A[2]);
	// for(int i=0;i<10;i++){
	// 	printf("%d\n",A[i]);
	// }
	for(int x:A){
		printf("%d\n",x );
	}
	return 0; 
}