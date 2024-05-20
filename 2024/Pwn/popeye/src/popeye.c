// gcc -o popeye popeye.c -fno-stack-protector -no-pie
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

__attribute__((constructor))
void __constructor__(){
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    signal(SIGALRM, exit);
    alarm(0x20);
}

void fini() {
    __asm__(
        "ldp x0, x1, [sp]\t\n"
        "ldp x29, x30, [sp], #0x20\t\n"
    );
}

void vuln() {
    printf("[To make it easier: %p]\n", puts);
    char buffer[0x20];
    gets(buffer);
}

int main() {
    puts("Do you not really know what there is to be known.");
    vuln();

    return 0;
}