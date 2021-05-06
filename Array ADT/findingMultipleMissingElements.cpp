#include<iostream>
#include<stdio.h>

using namespace std;

struct Array {
    int A[10];
    int size;
};

void FindMultipleMissingElements(struct Array arr) {
    int diff = arr.A[0] - 0;
    for (int i = 0; i < arr.size; i++) {
        if (arr.A[i] - i != diff) {
            while (diff < arr.A[i] - i) {
                cout << i + diff << endl;
                diff++;
            }
        }
    }
}

int main() {
        struct Array arr = {{3,4,5,6,7,9,10,13,14,15}, 10};
        FindMultipleMissingElements(arr);
        return 0;
    }

