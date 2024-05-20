// Name: babysbx.c
// Compile: gcc -o babysbx babysbx.c -lseccomp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <seccomp.h>
#include <sys/mman.h>
#include <sys/prctl.h>

#define PAGE_SIZE 0x1000

__attribute__((constructor))
void __constructor__(){
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    signal(SIGALRM, exit);
    alarm(0x20);
}

int validate(uint8_t *sc, int len) {
    // Validate if no int 0x80/syscall instruction exists:
    const short _nn = 2;
    for(int i = 0; i < (PAGE_SIZE-1); i++) {
        const char *blocklist[3] = {
            {"\xCD\x80"},
            {"\x0F\x05"},
            {"\x0F\x34"}
        };
        char sub_sc[_nn+1];
        memset(sub_sc, 0x0, _nn+1);
        memcpy(sub_sc, sc+i, _nn);
        for(int i = 0; i < 3; i++)
            if(memcmp(sub_sc, blocklist[i], _nn) == 0) {
                puts("Invalid instruction(s) found!");
                return 1;
            }
    }

    const uint8_t banned[] = {
        0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8E,
        0xA0, 0xA1, 0xA2, 0xA3,
        0xA4, 0xA5,
        0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7,
        0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,
        0xC6, 0xC7
    };

    for (int i = 0; i < len; i++)
        for (int j = 0; j < sizeof(banned); j++)
            if (sc[i] == banned[j]) {
                puts("Invalid instruction(s) found!");
                return 1;
            }
    return 0;
}

void init_reg() {
    asm("xor %rbx, %rbx");
    asm("xor %rcx, %rcx");
    asm("xor %rdx, %rdx");
    asm("xor %rdi, %rdi");
    asm("xor %rsi, %rsi");
    asm("xor %r8, %r8");
    asm("xor %r9, %r9");
    asm("xor %r10, %r10");
    asm("xor %r11, %r11");
    asm("xor %r12, %r12");
    asm("xor %r13, %r13");
    asm("xor %r14, %r14");
    asm("xor %r15, %r15");
}

void init_sbx() {

    scmp_filter_ctx ctx;
    ctx = seccomp_init(SCMP_ACT_ALLOW);

    if (ctx == NULL) exit(0);

    seccomp_rule_add(ctx, SCMP_ACT_KILL, SCMP_SYS(open), 0);
    seccomp_rule_add(ctx, SCMP_ACT_KILL, SCMP_SYS(execve), 0);
    seccomp_rule_add(ctx, SCMP_ACT_KILL, SCMP_SYS(execveat), 0);
    seccomp_rule_add(ctx, SCMP_ACT_KILL, SCMP_SYS(write), 0);
    seccomp_rule_add(ctx, SCMP_ACT_KILL, SCMP_SYS(read), 0);
    seccomp_rule_add(ctx, SCMP_ACT_KILL, 0x10B, 0);
    seccomp_rule_add(ctx, SCMP_ACT_KILL, 0x142, 0);
    seccomp_rule_add(ctx, SCMP_ACT_KILL, 0x127, 0);
    seccomp_rule_add(ctx, SCMP_ACT_KILL, 0xBB, 0);
    seccomp_load(ctx);
}

int main(int argc, char *argv[]) {

    char *sc = (char*)mmap(
        (void*)0xDEAD0000,
        PAGE_SIZE,
        PROT_EXEC | PROT_READ | PROT_WRITE,
        MAP_SHARED | MAP_ANONYMOUS,
        -1, 0LL);
    memset(sc, 0x00, PAGE_SIZE);

    printf("Give me your shellcode: ");
    read(0, sc, PAGE_SIZE);

    puts("==> Validating shellcode so it doesn't contain any invalid instruction.");
    if(validate(sc, PAGE_SIZE)) {
        puts("Nope. Can't run this shellcode.");
        exit(1);
    }
    
    puts("Shellcode looks clean. Invoking..");
    init_sbx();
    init_reg();
    ((void (*)(void))sc)();

}