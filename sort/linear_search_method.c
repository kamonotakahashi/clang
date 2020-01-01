#include <stdio.h>

#define ASC 1
#define DESC 2

int length(int *data) {
    int count = 0;
    while(*data != -1) {
        ++data;
        count++;
    }
    return count;
}

int main (void) {
    int data[] = {51,3,2,1,6,-1};
    printf("%d", length(data) );
}
