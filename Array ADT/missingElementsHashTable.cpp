#include <iostream>
using namespace std;

struct Array
{
 int A[10];
 int size;
};

void findMissing(struct Array *a, int n, int low, int high) {

    // Creating and initializing hash array with 0
    // Size of hash array = maximum element in input array
    int h[high];
    for (int i = 0; i < high; i++) {
        h[i] = 0;
    }
    
    // Incrementing hash table values as per the numbers in
    // original input array
    for (int i = 0; i < n; i++) {
        h[a->A[i]]++;
    }
    
    printf("Missing Elements :\n");
    for (int i = low; i <= high; i++) {
        if (h[i] == 0) {
            printf("%d\t", i);
        }
    }
}

// Driver program
int main()
{
   struct Array arr={{2,4,6,8},10};
   int n = sizeof(arr) / sizeof(arr.A[0]);
   int low = 1, high = 9;
   findMissing(&arr, n, low, high);
   return 0;
}
