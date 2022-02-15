
CC = gcc
CFLAGS = -I.
DEPS = cache.h

.PHONY = clean  # prevents `make` from doing something with a file name "clean"

%.o: %.c $(DEPS)  # before .o is compiled; check the content of .c and DEPS.
	$(CC) -c -o $@ $< $(CFLAGS)

a: a.o b.o
	$(CC) -o a a.o b.o

clean:
	rm -f *.o a