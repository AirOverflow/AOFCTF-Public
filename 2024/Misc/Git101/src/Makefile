# Author: @TheFlash2k

CHAL_NAME := main
SRC := $(CHAL_NAME).c
TAR_FILE := $(CHAL_NAME).tar
CONTAINER_NAME := ctf-$(CHAL_NAME)
DEFAULT_FLAG := "CTF{F4k3_fl4g_f0r_t3st1ng}"

# FLAGS
CC := gcc
FLAGS := -w -static

all:
	$(CC) -o $(CHAL_NAME) $(SRC) $(FLAGS)
	
writeup:
	mv -f exploit.py ../writeup/
	cp $(CHAL_NAME) ../writeup/
	echo "# $(CHAL_NAME)" > ../writeup/WRITEUP.md
	
clean:
	rm -f $(CHAL_NAME)
