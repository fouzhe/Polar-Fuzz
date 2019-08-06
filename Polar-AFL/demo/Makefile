.PHONY: all clean

CC = ../afl-clang-fast

all:
	$(CC) -g -fsanitize=address -o test test.c
	../afl-fuzz -i IN -o OUT -m none -j ./JSON_IN -P ./test @@

clean:
	rm -rf test
