# non-standard compilations
# link math library
palindromeinteger-int: palindromeinteger-int.c
	gcc -Wall $^ -o $@.o -lm

# use linkedlist.c
addnumbersaslists combinelist: linkedlist.c linkedlist.h

# basic compilation pattern
%: %.c ; gcc -Wall $^ -o $@.o

# delete all .o files
.PHONY: clean
clean:
	rm *.o
