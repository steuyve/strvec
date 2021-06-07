CC=${ccomp}
CFLAGS=-Wall -Wextra -pedantic -std=c99
SANFLAGS=-fsanitize=undefined -fsanitize=address -fno-omit-frame-pointer

.DEFAULT_GOAL := test

strvec: strvec.c
	$(CC) -g $(CFLAGS) $(SANFLAGS) -c -o bin/strvec.o strvec.c

test: strvec
	$(CC) -g $(CFLAGS) $(SANFLAGS) -o bin/test bin/strvec.o test/test.c

strvec-valgrind: strvec.c
	$(CC) -g $(CFLAGS) -c -o bin/strvec.o strvec.c

test-valgrind: strvec-valgrind
	$(CC) -g $(CFLAGS) -o bin/test bin/strvec.o test/test.c
