NAME = library
CC = cc
CFLAGS = -Wall -Wextra -Werror
BUFFER_SIZE = 10000

DEPDIR = ../
HEADER = -I../

test1 = tests.txt
test2 = 1char.txt
test3 = 1char_nl.txt
test4 = only_nl.txt
test5 = multiple_nl.txt
test6 = words.txt
test7 = big_line_no_nl.txt
test8 = big_line_with_nl.txt

SRC := $(wildcard $(DEPDIR)*.c)

OBJ := $(SRC: %.c = $(DEPDIR)%.o)

all: test1 test2 test3 test4 test5 test6 

test1:
	$(CC) $(CFLAGS) ${SRC} $(HEADER) main.c -D BUFFER_SIZE=$(BUFFER_SIZE)
	./a.out $(test1)

test2:
	$(CC) $(CFLAGS) ${SRC} $(HEADER) main.c -D BUFFER_SIZE=$(BUFFER_SIZE)
	./a.out $(test2)

test3:
	$(CC) $(CFLAGS) ${SRC} $(HEADER) main.c -D BUFFER_SIZE=$(BUFFER_SIZE)
	./a.out $(test3)

test4:
	$(CC) $(CFLAGS) ${SRC} $(HEADER) main.c -D BUFFER_SIZE=$(BUFFER_SIZE)
	./a.out $(test4)

test5:
	$(CC) $(CFLAGS) ${SRC} $(HEADER) main.c -D BUFFER_SIZE=$(BUFFER_SIZE)
	./a.out $(test5)

test6:
	$(CC) $(CFLAGS) ${SRC} $(HEADER) main.c -D BUFFER_SIZE=$(BUFFER_SIZE)
	./a.out $(test6)

test7:
	$(CC) $(CFLAGS) ${SRC} $(HEADER) main.c -D BUFFER_SIZE=$(BUFFER_SIZE)
	./a.out $(test7)

test8:
	$(CC) $(CFLAGS) ${SRC} $(HEADER) main.c -D BUFFER_SIZE=$(BUFFER_SIZE)
	./a.out $(test8)

val:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out $(test8)

h:
	gdb ./a.out $(test5)
