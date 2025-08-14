NAME = library
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEPDIR = ../
HEADER = -I../
test1 = tests.txt
test2 = 1char.txt
test3 = 1char_nl.txt
test4 = only_nl.txt
test5 = multiple_nl.txt
test6 = words.txt


SRC := $(wildcard $(DEPDIR)*.c)

OBJ := $(SRC: %.c = $(DEPDIR)%.o)

all: test1 test2 test3 test4 test5 test6 

test1:
	cc $(CFLAGS) ${SRC} $(HEADER) main.c
	./a.out $(test1)

test2:
	cc $(CFLAGS) ${SRC} $(HEADER) main.c
	./a.out $(test2)

test3:
	cc $(CFLAGS) ${SRC} $(HEADER) main.c
	./a.out $(test3)

test4:
	cc $(CFLAGS) ${SRC} $(HEADER) main.c
	./a.out $(test4)

test5:
	cc $(CFLAGS) ${SRC} $(HEADER) main.c
	./a.out $(test5)

test6:
	cc $(CFLAGS) ${SRC} $(HEADER) main.c 
	./a.out $(test6)
