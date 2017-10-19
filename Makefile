CC=gcc
CFLAGS=-I. -Wall -std=gnu99 -Wno-endif-labels
DEPS = 
OBJ = minsh.o

all: $(OBJ)

%.o: %.c $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

install:
	install -s $(OBJ) /usr/bin/minsh


.PHONY : clean
clean:
	rm $(OBJ)
.PHONY : test-install
test-install:
	install -s $(OBJ) minsh
