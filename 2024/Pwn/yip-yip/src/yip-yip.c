// Compile: gcc -o yip-yip yip-yip.c

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_SZ 0x18
#define MAX_USER_SZ 0x8

__attribute__((constructor))
void __constructor__(){
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    signal(SIGALRM, exit);
    alarm(0x20);
}

void get_input(int *in) {
    // Secure integer input function.
    // https://stackoverflow.com/questions/41145908/how-to-stop-user-entering-char-as-int-input-in-c
    char next;
    if (scanf("%d", in) < 0 || *in < 0 || ((next = getchar()) != EOF && next != '\n')) {
         clearerr(stdin);
         do next = getchar(); while (next != EOF && next != '\n');
         clearerr(stdin);
    }
}

void err(int code) {
    switch(code) {
    case 0:
        printf("[ERROR] - Contact the administrator.\n");
        break;
    case 18:
        printf("You are too young to be doing this.\n");
        break;
    default:
        printf("Are your trying do something naughty??\n");
    }
    exit(-1);
}


int read_flag(char* flag_buf) {
    if(!flag_buf) err(0);
    memset(flag_buf, 0, 0x100);
    FILE *fp = fopen("flag.txt", "r");
    if(!fp) err(0);
    return fread(flag_buf, 1, 0x100, fp);
}

typedef enum {
    MALE,
    FEMALE,
    OTHER,
    NONE
} gender_t;

typedef struct {
    char username[MAX_INPUT_SZ];
    int age;
    gender_t gender;
} user_t;
int is_registered = 0;

void prompt_input(char* msg, char* buffer, size_t sz) {
    printf("%s", msg);
    read(stdin, buffer, sz);
}

char* gender_to_char(gender_t gender) {
    return ((gender == MALE) ? 
        "MALE" : (
            (gender == FEMALE) ? "FEMALE" : "OTHER"
        ));
}

void print_user(const user_t* user) {
    printf("Username   : %s\n", user->username);
    if(user->age < 18) err(18);
    printf("Age        : %d\n", user->age);
    printf("Gender     : %s\n", gender_to_char(user->gender));
}

int menu() {
    int idx;
    printf(" === Reg-Menu ===\n");
    printf("01. Register yourself\n");
    printf("02. Check your details\n");
    printf("03. Un-register yourself\n");
    printf("69. Get the flag\n");
    printf("00. Exit\n");
    printf(">> ");
    get_input(&idx);
    return idx;
}

void setup_user(user_t *user) {
    if(!user) err(1);
    memset(user->username, NULL, MAX_INPUT_SZ);
    user->age = 0;
    user->gender = NONE;
    is_registered = 0;
}

void register_user(user_t* user) {
    if(!user) err(1);
    if(is_registered) {
        printf("You cannot register twice.");
        return;
    }
    printf("Enter your username: ");
    read(0, user->username, MAX_INPUT_SZ);

    printf("What's your age? ");
    scanf("%d", &user->age);

    printf("What's your gender (0=Male, 1=Female, 2=Other)? ");
    scanf("%d", &user->gender);

    printf("User registered successfully!\n");
}

int main() {

    user_t user;
    char flag[0x100];
    int opt;

    setup_user(&user);

    while((opt = menu())) {
        switch(opt) {
        case 1:
            register_user(&user);
            break;
        case 2:
            print_user(&user);
            break;
        case 3:
            setup_user(&user);
            break;
        case 69:
            read_flag(flag);
            break;
        default:
            printf("Invalid choice. Try again..\n");
            break;
        }
    }
}