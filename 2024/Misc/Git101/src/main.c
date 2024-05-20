#include <stdio.h>
#include <unistd.h>

void bloat() {
    puts("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Blandit massa enim nec dui. Sed tempus urna et pharetra pharetra massa massa ultricies. Faucibus ornare suspendisse sed nisi lacus. Vulputate enim nulla aliquet porttitor lacus luctus accumsan tortor.");
}

void bloat_2() {
    char flag_buf[0x100];
    memset(flag_buf, 0, 0x100);
    FILE *fp = fopen("flag.txt", "r");
    if(!fp) {
        puts("Something went wrong!");
        exit(1);
    }
    fread(flag_buf, 1, 0x100, fp);
    puts("Good job!\n.... I thought you were smarter.\n");
}

void type_out(char* buffer, size_t sz, int delay, int key) {
    for(int i = 0; i < sz; i++) {
        putc(buffer[i]^key, stdout);
        fflush(stdout);
        sleep(delay);
    }
    puts("");
}

void bloat_3() {
    char msg[] = "I'm sorry, I'm really slow at this typing.\0";
    type_out(msg, strlen(msg), 1, 0);
    unsigned char flag[] = { 0x28, 0x26, 0x2f, 0x2a, 0x3d, 0x2f, 0x12, 0xe, 0x58, 0x1d, 0x36, 0x58, 0x1a, 0x36, 0x1b, 0x5a, 0x8, 0x5, 0x5, 0x10, 0x36, 0x1c, 0x1a, 0x5a, 0xf, 0x1c, 0x5, 0x36, 0x10, 0x59, 0x1c, 0x36, 0x1a, 0x1, 0x59, 0x1c, 0x5, 0xd, 0x36, 0x5, 0x5a, 0x5d, 0x1b, 0x7, 0x36, 0x58, 0x1d, 0x14, 0x0 };
    type_out(flag, strlen(flag), 1, 0x69);
}

int main(int argc, char* argv[], char* envp[]) {


    for(int i = 0;i < 5; i++) {
        bloat();
        sleep(2);
    }
    bloat_2();
    sleep(10);
    printf("All right, I'll give you the flag\n");
    bloat_3();
    return 0;
}