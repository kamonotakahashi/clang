#include <stdio.h>

#define ARGMENT_LENGTH 4

int checkArgmentLength(int argc) {
    if(argc <= ARGMENT_LENGTH) {
        return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {

    if( checkArgmentLength(argc) == 0 ) {
        printf("A");
    }

}
