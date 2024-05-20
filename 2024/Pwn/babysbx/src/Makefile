# Author: @TheFlash2k

CHAL_NAME := babysbx
SRC := $(CHAL_NAME).c
TAR_FILE := $(CHAL_NAME).tar
CONTAINER_NAME := aofctf_pwn_babypwn
DEFAULT_FLAG := "CTF{F4k3_fl4g_f0r_t3st1ng}"

# FLAGS
CC := gcc
FLAGS := -w -lseccomp

all:
	$(CC) -o $(CHAL_NAME) $(SRC) $(FLAGS)

dist:
	mv flag.txt og_flag.txt
	echo $(DEFAULT_FLAG) > flag.txt
	# you can change these files to your likings
	tar -zcvf $(TAR_FILE) $(CHAL_NAME) Dockerfile flag.txt
	mv og_flag.txt flag.txt
	rm -f ../dist/$(TAR_FILE)
	mv $(TAR_FILE) ../dist/

build:
	docker build -t $(CONTAINER_NAME) .

run:
	docker run -it --rm -p1337:8000 --hostname $(CHAL_NAME) --name $(CONTAINER_NAME) $(CONTAINER_NAME)

stop:
	docker stop $(CONTAINER_NAME)

writeup:
	mv -f exploit.py ../writeup/
	cp $(CHAL_NAME) ../writeup/
	echo "# $(CHAL_NAME)" > ../writeup/WRITEUP.md
	
clean:
	rm -f $(CHAL_NAME)
	docker rmi $(CONTAINER_NAME)
