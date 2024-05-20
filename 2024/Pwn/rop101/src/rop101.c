#include <unistd.h>

void __fini() {
	asm(
		"xor %rax, %rax;"
		"syscall;"
		"ret;"

		"pop %rsi;"
		"ret;"
	);
}

int main() {
  char buf[16];
  read(0, buf ,1024);
}
