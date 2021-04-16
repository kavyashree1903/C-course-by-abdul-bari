#include <iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void display(struct Array arr){
    printf("\nElements are:\n");
    for (int i = 0; i < arr.length; i++){
    cout << arr.A[i] << " ";
}
}
 

int main() {
    struct Array arr;
    int n,i;
    printf("Input size of array");
    scanf("%d", &arr.size);
    arr.A = new int[sizeof(int)*arr.size];
    arr.length=0; //no elements inside the array at this stage
    
    printf("Enter the number of numbers");
    scanf("%d",&n);
    
    printf("Enter all elements:");
    for(i=0;i<n;i++){
        scanf("%d", &arr.A[i]);
    }
    
    arr.length=n; //n elements have been inserted
    display(arr);
    
    return 0;
}
