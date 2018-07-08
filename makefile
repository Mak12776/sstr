
test: test.c src/*.c src/*.h
	gcc -D_GNU_SOURCE test.c src/sstr.c -o bin/test -Werror -Wall -Wextra
