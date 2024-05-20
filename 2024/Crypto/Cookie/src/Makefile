# Author: @TheFlash2k

CHAL_NAME := main.py
CONTAINER_NAME := aofctf_crypto_cookie:latest
DEFAULT_FLAG := "CTF{F4k3_fl4g_f0r_t3st1ng}"

all:
	echo "Since this is a py-chal, no neeed"

dist:
	mkdir -p ../dist/
	cp $(CHAL_NAME) ../dist/

generate:
	# This will generate a dockerfile for your challenge accordingly:
	rm -f Dockerfile
	echo "FROM theflash2k/pwn-chal:py38" > Dockerfile
	echo "\nENV CHAL_NAME=$(CHAL_NAME)" >> Dockerfile
	echo "COPY . ." >> Dockerfile
	echo "\nEXPOSE 8000" >> Dockerfile

build:
	docker build -t $(CONTAINER_NAME) .

run:
	docker run -it --rm -p1337:8000 --hostname $(CHAL_NAME) --name $(CONTAINER_NAME) $(CONTAINER_NAME)

stop:
	docker stop $(CONTAINER_NAME)

writeup:
	mkdir -p ../writeup/
	mv -f solve.py ../writeup/
	cp $(CHAL_NAME) ../writeup/
	echo "# $(CHAL_NAME)" > ../writeup/WRITEUP.md
	
clean:
	rm ../dist/$(CHAL_NAME)
	docker rmi $(CONTAINER_NAME)
