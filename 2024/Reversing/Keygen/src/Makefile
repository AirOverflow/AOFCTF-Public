# Author: @TheFlash2k

CHAL_NAME := keygen
SRC := $(CHAL_NAME).cpp
TAR_FILE := $(CHAL_NAME).tar
CONTAINER_NAME := aofctf_rev_keygen
DEFAULT_FLAG := "AOFCTF{F4k3_fl4g_f0r_t3st1ng}"

# FLAGS
CC := g++
FLAGS := -w

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

generate:
	# This will generate a dockerfile for your challenge accordingly:
	rm -f Dockerfile
	echo "FROM theflash2k/pwn-chal:cpp" > Dockerfile
	echo "ENV CHAL_NAME=$(CHAL_NAME)" >> Dockerfile
	echo 'COPY $${CHAL_NAME} .' >> Dockerfile
	echo "COPY flag.txt ." >> Dockerfile
	echo "EXPOSE 8000" >> Dockerfile

build:
	docker build -t $(CONTAINER_NAME) .

run:
	docker run -it --rm -p1337:8000 --hostname $(CHAL_NAME) --name $(CONTAINER_NAME) $(CONTAINER_NAME)

stop:
	docker stop $(CONTAINER_NAME)

writeup:
	mv -f solve.py ../writeup/
	cp $(CHAL_NAME) ../writeup/
	echo "# $(CHAL_NAME)" > ../writeup/WRITEUP.md
	
clean:
	rm -f $(CHAL_NAME)
	docker rmi $(CONTAINER_NAME)
