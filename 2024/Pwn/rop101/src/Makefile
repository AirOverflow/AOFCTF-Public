# Author: @TheFlash2k

CHAL_NAME := rop101
SRC := $(CHAL_NAME).c
TAR_FILE := $(CHAL_NAME).tar
CONTAINER_NAME := aofctf_pwn_rop101:latest
DEFAULT_FLAG := "AOFCTF{F4k3_fl4g_f0r_t3st1ng}"

# FLAGS
CC := gcc
FLAGS := -fno-stack-protector -no-pie -w

all:
	gcc -o $(CHAL_NAME) $(SRC) $(FLAGS)
dist:
	mkdir -p ../dist
	mv flag.txt og_flag.txt
	echo $(DEFAULT_FLAG) > flag.txt
	# you can change these files to your likings
	tar -zcvf $(TAR_FILE) $(CHAL_NAME) Dockerfile flag.txt
	mv og_flag.txt flag.txt
	rm -f ../dist/$(TAR_FILE)
	mv $(TAR_FILE) ../dist/

generate:
	# This will generate a dockerfile for your challenge accordingly:
	rm -f Dockerfile
	echo "FROM theflash2k/pwn-chal:latest" > Dockerfile
	echo "ENV CHAL_NAME=$(CHAL_NAME)" >> Dockerfile
	echo 'COPY $${CHAL_NAME} .' >> Dockerfile
	echo 'COPY ld-linux-x86-64.so.2 .'
	echo 'COPY libc.so.6 .'
	echo "EXPOSE 8000" >> Dockerfile

build:
	docker build -t $(CONTAINER_NAME) .

run:
	docker run -it --rm -p1337:8000 --hostname $(CHAL_NAME) --name $(CONTAINER_NAME) $(CONTAINER_NAME)

stop:
	docker stop $(CONTAINER_NAME)

writeup:
	mkdir -p ../writeup
	mv -f exploit.py ../writeup/
	cp $(CHAL_NAME) ../writeup/
	echo "# $(CHAL_NAME)" > ../writeup/WRITEUP.md
	
clean:
	rm -f $(CHAL_NAME)
	docker rmi $(CONTAINER_NAME)
