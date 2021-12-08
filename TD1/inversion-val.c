#include <stdio.h>

int main() {
   
    int a, b, c;
    scanf("%d %d", &a, &b);
    //Invertes the values of a and b
    c = a;
    a = b;
    b = c;

    printf("%d %d \n", a, b);    
}   