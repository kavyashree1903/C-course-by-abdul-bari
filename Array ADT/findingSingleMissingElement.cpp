#include <iostream>
using namespace std;

struct Array {
    int *A;
    int size;
};

void FindSingleMissingElement(struct Array arr) {
    int low = arr.A[0];
    int diff = low - 0;
    for (int i = 0; i < arr.size; i++) {
        if (arr.A[i] - i != diff) {
            cout << "Missing element is: " << i + diff << endl;
            return;
        }
    }
    cout << "No Missing Element\n";
}
int main() {
    struct Array arr;
    arr.A = new int[10];
    arr.size = 10;
    
    arr.A[0] = 8;
    arr.A[1] = 10;
    arr.A[2] = 11;
    arr.A[3] = 12;
    arr.A[4] = 13;
    arr.A[5] = 14;
    arr.A[6] = 15;
    arr.A[7] = 16;
    arr.A[8] = 17;
    arr.A[9] = 18;
    FindSingleMissingElement(arr);
    delete []arr.A;
    return 0;
}
