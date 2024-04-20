#include <stdio.h>

void myFunction();

int main() {
    printf("hello\n");

    int x;
    x = 7;

    print("%d\n", x);

    myFunction();

    return 0;
}

void myFunction(){
    printf("yeehaw");
}