CC=gcc
CFLAGS=-Wall -Werror

all: linkedList
linkedList: linkedList.o linkedlist_functions.o
linkedList.o: linkedList.c linkedlist_functions.c

clean:
	rm -f linkedList linkedList.o linkedlist_functions.o
run: linkedList
	./linkedList
