CC=gcc
CFLAGS=-Wall

all: hello
hello: hello.o hello_functions.o
hello.o: hello.c hello_functions.c

clean:
	rm -f hello hello.o hello_functions.o
run: hello
	./hello
