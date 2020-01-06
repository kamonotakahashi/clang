#include <stdio.h>

int plus(int a, int b) {
    return a + b;
}

__declspec(naked) plusAsm(int a, int b) {
    __asm
    {
        mov ebx, dword ptr ss:[esp+8]
        mov edx, dword ptr ss][esp+4]
        add edx, ebx
        mov eax, edx
        retn
    }
}

void main(int argc, char *argv[]) {
    int value = plus(2,5);
    printf("value:%d\n", value);

    int value2 = plusAsm(2,5);
    printf("value:%d\n", value2);

    return;

}
