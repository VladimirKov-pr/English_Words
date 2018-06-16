all: program

program: build/main.o build/functions.o build/game.o bin 
	gcc -Wall -Werror build/main.o build/functions.o build/game.o -o bin/program

test: build/test.o build/functions.o bin
	gcc -Wall -Werror build/test.o build/functions.o -o bin/test

build/test.o: test/test.c
	gcc -Wall -Werror -I thirdparty -I source -c test/test.c -o build/test.o

build/main.o: source/main.c build
	gcc -std=c99 -Wall -Werror -c source/main.c -o build/main.o

build/functions.o: source/functions.c build
	gcc -std=c99 -Wall -Werror -c source/functions.c -o build/functions.o

build/game.o: source/game.c build
	gcc -std=c99 -Wall -Werror -c source/game.c -o build/game.o	

build:
	mkdir build

bin:
	mkdir bin

.PHONY: clean

clean:
	rm -rf bin/program build/*.o bin/test