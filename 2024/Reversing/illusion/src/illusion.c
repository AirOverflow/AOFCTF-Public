#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/user.h>

int flagcheck(char *arg)
{

    int len = strlen(arg);
    uint32_t x[] = {3506868002 , 3542527462 , 3106054992 , 1250615634 , 961209986 , 3524749440 , 1748173521 , 2304148768 , 922320063};
    uint32_t y[] = {3893302130 , 1212257138 , 3504301936 , 3476729895 , 1478866023 , 4171846495 , 3230582564 , 3494877010 , 804284557};
    uint32_t z[] = {1354022296 , 3896290713 , 823521428 , 101927400 , 1799038865 , 3089123365 , 3408375811 , 3359386955 , 936104550};
    uint32_t result[] = {2013338292 , 3643337960 , 1751534901 , 2387432024 , 4206284355 , 3777020566 , 2691371045 , 1685726042 , 630665147 , 1943452866 , 3723111615 , 2688725002 , 1186917910 , 1116095036 , 2533966958 , 3849331869 , 3826093588 , 3903204169 , 2152322872 , 2424245532 , 1535477024 , 4090076233 , 326779556 , 950451249 , 1925260118 , 1119821224 , 3660956905 , 2474639220 , 1610927943 , 2902325634 , 2502066477 , 1934661818};
    uint32_t lol[] = {6648654, 5804428, 7049387, 6063163, 7142764, 6475427, 6893100, 6235081, 7396978, 6120568, 6531884, 7489266, 8041647, 6496754, 6849960, 7194588, 5985314, 5835230, 5546464, 8095440, 8869712, 5612646, 7986223, 7703728, 6366439, 8356385, 8194517, 8307680, 6440881, 5255140, 7894370, 6717494};
    int counter = 0;
    if (arg[0] != 'A'){
    	return 0;
    }
    if (len != 32){
    	return 0;
    }
    register int illusion asm ("r8") = lol[10];
    int val = 0;

    asm("mov (0), %rax\n");
    val = x[1] ^ x[7] ^ x[0] ^ y[2] ^ (arg[0]) ^ illusion; 
    if (val == result[0]){
    	counter++;
    }
    illusion = lol[9];
    asm("mov (0), %rax\n");
    val = x[2] ^ x[6] ^ x[6] ^ x[3] ^ (arg[1]) ^ illusion; 
    if (val == result[1]){
    	counter++;
    }
    illusion = lol[8];
    asm("mov (0), %rax\n");
    val = x[0] ^ z[1] ^ y[2] ^ x[5] ^ (arg[2]) ^ illusion; 
    if (val == result[2]){
    	counter++;
    }
    illusion = lol[7];
    asm("mov (0), %rax\n");
    val = y[1] ^ y[2] ^ z[6] ^ x[2] ^ (arg[3]) ^ illusion; 
    if (val == result[3]){
    	counter++;
    }
    illusion = lol[6];
    asm("mov (0), %rax\n");
    val = x[3] ^ x[2] ^ x[6] ^ x[4] ^ (arg[4]) ^ illusion;  
    if (val == result[4]){
    	counter++;
    }
    illusion = lol[5];
    asm("mov (0), %rax\n");
    val = z[2] ^ x[5] ^ y[2] ^ y[5] ^ (arg[5]) ^ illusion;  
    if (val == result[5]){
    	counter++;
    }
    illusion = lol[4];
    asm("mov (0), %rax\n");
    val = y[4] ^ z[5] ^ y[6] ^ z[5] ^ (arg[6]) ^ illusion; 
    if (val == result[6]){
    	counter++;
    }
    illusion = lol[3];
    asm("mov (0), %rax\n");
    val = y[7] ^ y[7] ^ y[3] ^ z[5] ^ (arg[7]) ^ illusion;  
    if (val == result[7]){
    	counter++;
    }
    illusion = lol[2];
    asm("mov (0), %rax\n");
    val = y[8] ^ z[0] ^ z[3] ^ x[8] ^ (arg[8]) ^ illusion; 
    if (val == result[8]){
    	counter++;
    }
    illusion = lol[1];
    asm("mov (0), %rax\n");
    val = z[0] ^ y[2] ^ x[7] ^ z[3] ^ (arg[9]) ^ illusion;  
    if (val == result[9]){
    	counter++;
    }
    illusion = lol[0];
    asm("mov (0), %rax\n");
    val = x[4] ^ x[4] ^ y[3] ^ y[4] ^ (arg[10]) ^ illusion;  
    if (val == result[10]){
    	counter++;
    }
    illusion = lol[20];
    asm("mov (0), %rax\n");
    val = y[6] ^ z[3] ^ z[8] ^ y[8] ^ (arg[11]) ^ illusion; 
    if (val == result[11]){
    	counter++;
    }
    illusion = lol[19];
    asm("mov (0), %rax\n");
    val = z[4] ^ z[4] ^ z[7] ^ z[7] ^ (arg[12]) ^ illusion;  
    if (val == result[12]){
    	counter++;
    }
    illusion = lol[18];
    asm("mov (0), %rax\n");
    val = y[6] ^ z[7] ^ y[1] ^ x[6] ^ (arg[13]) ^ illusion;  
    if (val == result[13]){
    	counter++;
    }
    illusion = lol[17];
    asm("mov (0), %rax\n");
    val = y[4] ^ x[3] ^ y[5] ^ y[1] ^ (arg[14]) ^ illusion;  
    if (val == result[14]){
    	counter++;
    }
    illusion = lol[16];
    asm("mov (0), %rax\n");
    val = y[3] ^ y[0] ^ x[4] ^ y[7] ^ (arg[15]) ^ illusion; 
    if (val == result[15]){
    	counter++;
    }
    illusion = lol[15];
    asm("mov (0), %rax\n");
    val = y[3] ^ x[7] ^ x[7] ^ x[3] ^ (arg[16]) ^ illusion; 
    if (val == result[16]){
    	counter++;
    }
    illusion = lol[14];
    asm("mov (0), %rax\n");
    val = z[2] ^ x[8] ^ y[7] ^ y[8] ^ (arg[17]) ^ illusion; 
    if (val == result[17]){
    	counter++;
    }
    illusion = lol[13];
    asm("mov (0), %rax\n");
    val = x[3] ^ x[8] ^ y[3] ^ z[2] ^ (arg[18]) ^ illusion; 
    if (val == result[18]){
    	counter++;
    }
    illusion = lol[12];
    asm("mov (0), %rax\n");
    val = z[1] ^ x[0] ^ z[3] ^ x[1] ^ (arg[19]) ^ illusion; 
    if (val == result[19]){
    	counter++;
    }
    illusion = lol[11];
    asm("mov (0), %rax\n");
    val = z[7] ^ y[0] ^ y[6] ^ y[0] ^ (arg[20]) ^ illusion;  
    if (val == result[20]){
    	counter++;
    }
    illusion = lol[31];
    asm("mov (0), %rax\n");
    val = y[0] ^ x[5] ^ x[1] ^ z[3] ^ (arg[21]) ^ illusion;  
    if (val == result[21]){
    	counter++;
    }
    illusion = lol[30];
    asm("mov (0), %rax\n");
    val = z[7] ^ x[5] ^ y[8] ^ x[8] ^ (arg[22]) ^ illusion; 
    if (val == result[22]){
    	counter++;
    }
    illusion = lol[29];
    asm("mov (0), %rax\n");
    val = x[7] ^ z[8] ^ x[3] ^ z[6] ^ (arg[23]) ^ illusion; 
    if (val == result[23]){
    	counter++;
    }
    illusion = lol[28];
    asm("mov (0), %rax\n");
    val = x[3] ^ x[3] ^ x[1] ^ y[3] ^ (arg[24]) ^ illusion; 
    if (val == result[24]){
    	counter++;
    }
    illusion = lol[27];
    asm("mov (0), %rax\n");
    val = x[7] ^ z[5] ^ y[0] ^ y[7] ^ (arg[25]) ^ illusion; 
    if (val == result[25]){
    	counter++;
    }
    illusion = lol[26];
    asm("mov (0), %rax\n");
    val = z[2] ^ y[1] ^ x[1] ^ z[8] ^ (arg[26]) ^ illusion; 
    if (val == result[26]){
    	counter++;
    }
    illusion = lol[25];
    asm("mov (0), %rax\n");
    val = z[7] ^ x[3] ^ z[3] ^ z[3] ^ (arg[27]) ^ illusion; 
    if (val == result[27]){
    	counter++;
    }
    illusion = lol[24];
    asm("mov (0), %rax\n");
    val = x[2] ^ x[7] ^ y[2] ^ y[5] ^ (arg[28]) ^ illusion; 
    if (val == result[28]){
    	counter++;
    }
    illusion = lol[23];
    asm("mov (0), %rax\n");
    val = y[3] ^ z[3] ^ y[7] ^ x[5] ^ (arg[29]) ^ illusion; 
    if (val == result[29]){
    	counter++;
    }
    illusion = lol[22];
    asm("mov (0), %rax\n");
    val = y[3] ^ x[6] ^ z[0] ^ y[4] ^ (arg[30]) ^ illusion;
    if (val == result[30]){
    	counter++;
    }
    illusion = lol[21];
    asm("mov (0), %rax\n");
    val = z[6] ^ z[6] ^ y[2] ^ z[5] ^ (arg[31]) ^ illusion; 
    if (val == result[31]){
    	counter++;
    }
    if (counter == 32){
    	return 1;
    }
    else{
    	return 0;
    }
}
int main(int argc, char **argv)
{
    if (argc != 2) {
        puts("where the flag at");
        exit(1);
    }
    pid_t pid;
    int status;
    struct user_regs_struct regs;
    pid = fork();
    if (pid == 0)
    {
        if (flagcheck(argv[1])){

        	puts("how did you get past my illusion, you must be hacking :/");
        }
        else{
        	puts("NOPE");
        }
        exit(0);
    }
    ptrace(PTRACE_ATTACH, pid, NULL, NULL);
    srand((unsigned int)argv[1][0]);
    while (1)
    {

        waitpid(pid, &status, 0);
        
        if (WIFEXITED(status)){
        	break;
        }
        if (WIFCONTINUED(status))
            continue;
        if (WIFSTOPPED(status) && WSTOPSIG(status) == SIGSEGV)
        {
            ptrace(PTRACE_GETREGS, pid, NULL, &regs);
            int randvalue = rand();
            regs.r8 = randvalue;
            regs.rip += 8;                   
            ptrace(PTRACE_SETREGS, pid, NULL, &regs);
        }
        ptrace(PTRACE_CONT, pid, NULL, NULL);
    }
    return 0;
}
