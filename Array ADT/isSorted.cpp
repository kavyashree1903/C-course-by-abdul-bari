#include <iostream>

struct Array {
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr) {
    printf("\nElements are: ");
    for (int i = 0; i < arr.length; i++) { printf("%d ", arr.A[i]);}
    printf("\n");
}

// SWAP function
void Swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}


void Reverse2(struct Array *arr) {
    // Swapping stops once i >= j
    for (int i = 0, j = arr->length-1; i<j; i++, j--)
        Swap(&arr->A[i],&arr->A[j]);
}

void InsertSort(struct Array *arr, int x) {
    int i = arr->length-1;
    // Check that there is free space in the array
    if (arr->length == arr->size)
        return;
    // Shift all the elements which are larger than 'x' to the right
    // Also ensure that 'i' will not go to negative
    while (i >= 0 && arr->A[i] > x) {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    // Once we have exited the loop, we know that A[i] is less than or equal to 'x'
    // So we need to insert 'x' in A[i+1]
    arr->A[i+1] = x;
    arr->length++; // Increment the length of the array
}

// isSORTED - Given an array, it will check if the array is sorted
// Passing the 'arr' by value because we are NOT modifying it.
bool isSorted(struct Array arr) {
    // i stops before the last element in the list
    for (int i = 0; i < arr.length-1; i++) {
        if (arr.A[i] > arr.A[i+1])
            return false;
    }
    return true;
}

// REARRANGE - Rearranges an array (unsorted or sorted) so that
// all neg numbers are on the left and all pos numbers are on the right
// Passing the 'arr' by address because we are modifying it.
void Rearrange(struct Array *arr) {
    int i = 0, j = arr->length-1;
    
    while (i < j) {
        while (arr->A[i] < 0) i++;
        while (arr->A[j] >= 0) j--;
        if (i < j)
            Swap(&arr->A[i], &arr->A[j]);
    }
}

int main(){
    struct Array arr = {{2,3,5,10,15}, 10, 5};
    InsertSort(&arr, 4);
    Display(arr);
    struct Array arr2 = {{5,7,-10,4,-3,2}, 10, 6};
    Rearrange(&arr2);
    Display(arr2);
    return 0;
}
