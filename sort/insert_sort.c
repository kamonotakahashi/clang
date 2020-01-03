#include <stdio.h>

#define ASC 1
#define DESC 2

void sort(int *data, int length, int types);

int main(void) {
    int data[] = {53,123,56,123,522};
    int length = sizeof(data)/sizeof(data[0]);

    //昇順
    sort(data, length, ASC);
    for(int i = 0; i < length; i++) {
        if(i != length - 1) {
            printf("%d,", data[i]);
        } else {
            printf("%d\n", data[i]);
        }
    }

    //降順
    sort(data, length, DESC);
    for(int i = 0; i < length; i++) {
        if(i != length - 1) {
            printf("%d,", data[i]);
        } else {
            printf("%d\n", data[i]);
        }
    }

    return 0;
}

void sort(int *data, int length, int types) {
    int max;
    int pos;

    if(types==ASC) {
        for(int i = length; i < length; i--) {
            max = 0;
            for(int x = i; x < length; x--) {
                if(max < data[x]) {
                    pos = x;
                    max = data[x];
                }
            }
            data[pos] = data[i];
            data[i] = max;
        }
    } else {
        for(int i = 0; i < length; i++) {
            max = 0;
            for(int x = i; x < length; x++) {
                if(max < data[x]) {
                    pos = x;
                    max = data[x];
                }
            }
            data[pos] = data[i];
            data[i] = max;
        }
    }
}
