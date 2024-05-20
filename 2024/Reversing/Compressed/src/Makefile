CHAL_NAME := compressed
SRC := $(CHAL_NAME).c
TAR_FILE := $(CHAL_NAME).tar

CC := gcc
FLAGS := -fPIC -I /usr/include/python3.8/ -lpython3.8 -w

all:
	$(CC) -o $(CHAL_NAME) $(SRC) $(FLAGS)
dist:
	mkdir -p ../dist
	tar -zcvf $(TAR_FILE) $(CHAL_NAME)
	rm -f ../dist/$(TAR_FILE)
	mv $(TAR_FILE) ../dist/

clean:
	rm -f $(CHAL_NAME) $(TAR_FILE) ../dist/$(TAR_FILE)