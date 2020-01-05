#include <stdio.h>
//
#define ASC 1
#define DESC 2

void sort(int *data, size_t length, int type);
void print_array(int *data, size_t length);

int main(void) {
    int data[] = {1,6,4,5,3,2,8,9,7,0};
    size_t length = sizeof(data) / sizeof(data[0]);
    print_array(data, length);
    sort(data, length, DESC);
    print_array(data, length);

    return 0;
}

void print_array(int *data, size_t length) {
    for(int i = 0; i < length; i++) {
        if(i != length - 1) {
            printf("%d,", data[i]);
        } else {
            printf("%d", data[i]);
        }

    }
    printf("\n");
}

void sort(int *data, size_t length, int type) {
    int tmp = 0;
    if(type == ASC) {
        for(int i = 0; i < length; i++) {
            for(int x = length - 1; i < x; x--) {
                if(0 >= x) continue;
                if(data[x] > data[x - 1]) {
                    tmp = data[x];
                    data[x] = data[x - 1];
                    data[x - 1] = tmp;
                }
            }
        }
    } else {
        for(int i = length - 1; 0 < i; i--) {
            for(int x = 0; x < i; x++) {
                if(data[x] > data[x + 1]) {
                    tmp = data[x];
                    data[x] = data[x + 1];
                    data[x + 1] = tmp;
                }
            }
        }
    }
}
