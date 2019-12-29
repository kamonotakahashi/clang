#include <stdio.h>

int main(void) {
    char test[255] = "SRORGLnTh2Q5fTwu";
    char *cp;
    char c;
    cp = &test[0];
    while ((c = *cp++) != 0) {
        printf("%d\n", c);
    }
    return 0;
}
