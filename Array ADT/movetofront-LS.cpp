#include<iostream>

struct Array
{
 int A[10];
 int size;
 int length;
};

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Display(struct Array arr)
 {
 int i;
 printf("\nElements are\n");
 for(i=0;i<arr.length;i++)
 printf("%d ",arr.A[i]);
 }

 int LinearSearch(struct Array *arr, int key)
 {
 int i;

     for(i=0; i<arr->length; i++){
     if(key==arr->A[i]){
         swap(&arr->A[i], &arr->A[i-1]);
         return i;
     }
 }
     return -1;
 }

int main()
{
struct Array arr1={{2,3,4,5,6},10,5};
    
printf("%d\n",LinearSearch(&arr1,5));
    
Display(arr1);
    
 return 0;
}
