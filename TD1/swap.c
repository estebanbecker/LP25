#include <stdio.h>

void swap(int *a, int *b);

int main() {
    int a, b;
    int *pa, *pb;
    pa = &a;
    pb = &b;

    scanf("%d %d", pa, pb);

    swap(pa, pb);
    printf("%d %d", a, b);
}

void swap(int *a, int *b){
    //swap the value of a and b
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}