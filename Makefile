all:
	gcc -o minsh minsh.c -Wall -std=gnu99
clean:
	rm minsh
install:
	mkdir -p ~/.local/bin/
	mv minsh ~/.local/bin/
