all:
	gcc -o minsh minsh.c -Wall -std=gnu99
clean:
	rm minsh
install:
	mv minsh ~/.local/bin/
