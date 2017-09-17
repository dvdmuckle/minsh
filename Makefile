CC=gcc
CFLAGS=-I. -Wall -std=gnu99 -coverage
DEPS =
OBJ = minsh.o

all: $(OBJ)

%.o: %.c $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

install:
	install -s minsh.o /usr/bin/minsh


.PHONY : clean
clean:
	rm $(OBJ)
.PHONY : test-install
test-install:
	install -s minsh.o minsh
