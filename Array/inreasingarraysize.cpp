#include <iostream>

int main() {
    int i;
    int *p = new int[5];
    int *q= new int[10];
    for(int i=0;i<5;i++){
        q[i]=p[i];
    }
    delete []p;
    p=q;
    q=NULL;
    for(i=0;i<5;i++)
    printf("%d \n",p[i]);
    return 0;
}
