#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *A;
    int size;
    int length;
};

void Display(struct Array arr) {
    printf("\nElements are: ");
    for (int i = 0; i < arr.length; i++) { printf("%d ", arr.A[i]);}
    printf("\n");
}


void Append(struct Array *arr, int x) {
    if (arr->length < arr->size) {
        arr->A[arr->length++] = x;
    }
}

void Insert(struct Array *arr, int index, int x) {
    if (index >= 0 && index <= arr->length) {
        for (int i = arr->length; i > index; i--) { arr->A[i] = arr->A[i-1]; }
        arr->A[index] = x;
        arr->length++; // Update the length of the array
    }
}

int Delete(struct Array *arr, int index) {
    int x = 0;
    if (index >= 0 && index <= arr->length-1) {
        x = arr->A[index];
        for (int i = index; i < arr->length-1; i++) {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

int LinearSearch(struct Array arr, int key) {
    
    for (int i = 0; i < arr.length; i++) {
        if (key == arr.A[i]) return i;
    }
    return -1;
}


int BinarySearch(struct Array arr, int key) {
    int l,mid,h;
    l = 0;
    h = arr.length - 1;
    while (l <= h) {
        mid = (l+h)/2;
        if (key == arr.A[mid]) { return mid; }
        else if (key < arr.A[mid]) { h = mid-1;}
        else { l = mid+1;}
    }
        return -1;
}

// BINRAY SEARCH - RECURSIVE
int RecBinarySearch(int a[], int l, int h, int key) {
    int mid;
    if (l <= h) {
        mid = (l+h)/2;
        if (key == a[mid]) { return mid; }
        else if (key < a[mid]) { return RecBinarySearch(a, l, mid-1, key); }
        else { return RecBinarySearch(a, mid+1, h, key); }
    }
    return -1;
}

int Get(struct Array arr, int index) {
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

void Set(struct Array *arr, int index, int x) {
    if (index >= 0 && index < arr->length)
        arr->A[index] = x;
}

int Max(struct Array arr) {
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++) {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

int Min(struct Array arr) {
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++) {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

int Sum(struct Array arr) {
    int s = 0;
    for (int i = 0; i < arr.length; i++)
        s += arr.A[i];
    return s;
}

float Avg(struct Array arr) {
    return (float) Sum(arr)/arr.length;
}

void Reverse(struct Array *arr) {
    int *B = (int *)malloc(arr->length*sizeof(int));
    // Copy the elements of 'A' to 'B' in REVERSE order
    for (int i = arr->length-1, j = 0; i >= 0; i--, j++)
        B[j] = arr->A[i];
    // Copy the elements of 'B' to 'A' in SAME order
    for (int i = 0; i < arr->length; i++)
        arr->A[i] = B[i];
    free(B); // To avoid memory leak
}

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
    if (arr->length == arr->size)
        return;
    while (i >= 0 && arr->A[i] > x) {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++; // Increment the length of the array
}

bool isSorted(struct Array arr) {
    // i stops before the last element in the list
    for (int i = 0; i < arr.length-1; i++) {
        if (arr.A[i] > arr.A[i+1])
            return false;
    }
    return true;
}

void Rearrange(struct Array *arr) { //all negative numbers on the left
    int i = 0, j = arr->length-1;
    
    while (i < j) {
        while (arr->A[i] < 0) i++;
        while (arr->A[j] >= 0) j--;
        if (i < j)
            Swap(&arr->A[i], &arr->A[j]);
    }
}

// MERGE - Merges two SORTED arrays
struct Array* Merge(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    // Once we reach this point, we know we have finished with one of the arrays
    // So all we have to do is copy the other array's elements to the end of 'arr3'
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
    return arr3;
}

// UNION Set operation for SORTED sets
// Merge set A and set B such that all of the elements in the new set is unique
struct Array* Union(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr1->A[i] > arr2->A[j])
            arr3->A[k++] = arr2->A[j++];
        // If A[i] == A[j], we only copy one of them to arr3
        else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    // Once we reach this point, we know we have finished with one of the arrays
    // So all we have to do is copy the other array's elements to the end of 'arr3'
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array* Intersection(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr1->A[i] > arr2->A[j])
            j++;
        // If A[i] == A[j], we only copy one of them to arr3
        else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array* Difference(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr1->A[i] > arr2->A[j])
            j++;
        else {
            i++;
            j++;
        }
    }

    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

int main(){
    struct Array arr1;
    int ch, x, index;
    
    printf("Enter the Size of Array: ");
    scanf("%d", &arr1.size);
    arr1.A = (int *)malloc(arr1.size*sizeof(int));
    arr1.length = 0;
    
    do {
        printf("MENU\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1: printf("Enter an element and index: ");
                scanf("%d%d", &x, &index);
                Insert(&arr1, index, x);
                break;
            case 2: printf("Enter index: ");
                scanf("%d", &index);
                x = Delete(&arr1, index);
                printf("Deleted element is %d\n", x);
                break;
            case 3: printf("Enter element to search: ");
                scanf("%d", &x);
                index = LinearSearch(arr1, x);
                printf("Element index is %d\n", index);
                break;
            case 4: printf("Sum is %d\n", Sum(arr1));
                break;
            case 5: Display(arr1);
                break;
            
        }
    } while(ch < 6);
    
    free(arr1.A);
    return 0;
}
