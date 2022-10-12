# This Makefile is set up for CS 201 A1
# by markem
# NOTE: All indented lines are indented with a tab character.
#       This is required.

CC = gcc
# flag all warning. default optimization level.
CFLAGS = -Wall -Og
# set for use in gdb
DFLAGS = -g
# For additional libraries, e.g. -lm
LDFLAGS =
PROGS = typing_word_game

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) $(DFLAGS) $< $(LDFLAGS) -o $@

clean:
	rm -f $(PROGS) *.o ~* a.out

# for use with autograding tools
reallyclean: clean
	rm -rf *.log feedback.txt __pycache__


