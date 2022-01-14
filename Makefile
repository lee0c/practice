# non-standard compilations

# use linkedlist.c
addnumbersaslists: $@.c linkedlist.c
	gcc -Wall $@.c linkedlist.c -o $@.out

combinelist: $@.c linkedlist.c
	gcc -Wall $@.c linkedlist.c -o $@.out

# link math library
palindromeinteger-int: $@.c
	gcc -Wall $@.c -o $@.out -lm

# catchall compilation
%: %.c
	gcc -Wall $@.c -o $@.out
