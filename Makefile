all:
	gcc -o minsh minsh.c -Wall -std=gnu99
clean:
	rm minsh
test-install:
	mkdir -p ~/.local/bin/
	mv minsh ~/.local/bin/
install:
	mv minsh /usr/bin/
