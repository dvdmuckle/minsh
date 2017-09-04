all:
	gcc -o minsh minsh.c -Wall
clean:
	rm minsh
install:
	mv minsh ~/.local/bin/
