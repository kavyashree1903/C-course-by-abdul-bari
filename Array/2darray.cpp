#include <iostream>

int main() {
    int A[3][4]={{1,2,3,4},{4,5,3,4},{5,6,7,8}};
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            printf("%d\n",A[i][j]);
        }
    }
    int *B[3];
    B[0]=new int[4];
    B[1]= new int[4];
    B[2]= new int [4];
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            printf("%d\n",B[i][j]);
        }
    }
    int **C;
    C= new int *[3];
    
    C[0]= new int[4];
    C[0]= new int[4];
    C[0]= new int[4];

    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            printf("%d\n",C[i][j]);
        }
    }
    return 0;
}
