#include <stdio.h>

#define LEFT_CHILD(i)  (((i) + 1) * 2 - 1)
#define RIGHT_CHILD(i) (((i) + 1) * 2)
#define PARENT(i)      (((i) + 1) / 2 - 1)

void heap_sort(int *data, int n_element_length);
void upheap(int *data, int n);
void downheap(int *data, int n);
void swap(int *data, int left, int right);
void print_array(int *data, int n_element_length);

int main (void) {

    int data[] = {20,1,4,6,8,312,3,222,456,2332};
    size_t length = sizeof(data) / sizeof(data[0]);

    print_array(data, length);
    heap_sort(data, length);
    print_array(data, length);
    return 0;
}

void print_array(int *data, int n_element_length) {
    for(int i = 0; i < n_element_length; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void heap_sort(int *data, int n_element_length) {
    int i = 0;

    while( ++i < n_element_length) {
        upheap(data, i);
    }

    while( --i > 0) {
        swap(data, 0, i);
        downheap(data, i);
    }
}

void upheap(int *data, int n) {
    while(n > 0) {
        int m = PARENT(n);
        if(data[m] < data[n]) {
            swap(data, m, n);
        } else {
            break;
        }
        n = m;
    }
}

void downheap(int *data, int n) {
    int m = 0;
    int tmp = 0;
    while(1) {
        int l_chld = LEFT_CHILD(m);
        int r_chld = RIGHT_CHILD(m);
        if(l_chld >= n) {
            break;
        }
        if(data[l_chld] > data[tmp]) {
            tmp = l_chld;
        }
        if((r_chld < n) && (data[r_chld] > data[tmp])) {
            tmp = r_chld;
        }
        if(tmp == m) {
            break;
        }
        swap(data, tmp, m);
        m = tmp;
    }
}

//入れ替え
void swap(int *data, int left, int right) {
    int tmpData = data[left];
    data[left] = data[right];
    data[right] = tmpData;
}
