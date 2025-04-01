#include <stdlib.h>
#include <stdio.h>

void min_test(int a, int b) {
    if(a < b) {
        printf("Mniejsza z podanych liczb to: %d\n", a);
    } else {
        printf("Mniejsza z podanych liczb to: %d\n", b);
    } 
}

int main() {
    min_test(3, 4);
    
    return 0;
}