CC=gcc
CFLAGS=-Iinclude -Wall -Werror
OBJ=build/main.o build/hello.o

hello: $(OBJ)
	$(CC) -o build/hello $(OBJ)

build/main.o: src/main.c include/hello.h
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/hello.o: src/hello.c include/hello.h
	$(CC) $(CFLAGS) -c src/hello.c -o build/hello.o

clean:
	rm -rf build/*.o build/hello
