CC = gcc
CFLAGS = -Wall

test: main.c mylib.c
	$(CC) $(CFLAGS) -fPIC -c mylib.c -o mylib.o
	$(CC) -shared mylib.o -o libmylib.so
	$(CC) $(CFLAGS) main.c -o test

clean:
	rm -f test libmylib.so mylib.o

