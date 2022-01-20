# non-standard compilations
# use linkedlist.c
addnumbersaslists combinelists: linkedlist.c linkedlist.h

# basic compilation pattern
%: %.c debug.h; gcc -Wall $^ -o $@.o -lm

# delete all .o files
.PHONY: clean
clean:
	rm *.o
