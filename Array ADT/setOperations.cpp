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

// Union of two arrays
struct Array* Union(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if(arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else{
            arr3->A[k++] = arr2->A[j++];
            i++;
        }
    }
    // So all we have to do is copy the other array's elements to the end of 'arr3'
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

// Intersection of two arrays
struct Array* Intersection(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]){
            i++;
        }
        else if(arr2->A[j] < arr1->A[i]){
            j++;
        }
        else{
            arr3->A[k++] = arr2->A[j++];
            i++;
        }
    }
    
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

// Difference of two arrays
struct Array* Difference(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if(arr2->A[j] < arr1->A[i])
            j++;
        else{
            i++;
            j++;
        }
    }
    // So all we have to do is copy the other array's elements to the end of 'arr3'
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    
    //don't copy elements from arr2
    
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}



int main(){
    struct Array arr1={{1,3,6,8,23},10,5};
    struct Array arr2={{2,3,5,8,56},10,5};
    struct Array *arr3;
    arr3 = Difference(&arr1, &arr2);
    Display(*arr3);
    return 0;
}
