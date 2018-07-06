test: *.c src/*.c src/*.h
	gcc test.c src/sstr.c -o bin/test
