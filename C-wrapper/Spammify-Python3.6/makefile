CC = gcc

default: pyexamples

pyexamples: spammify.c
	$(CC) spammify.c -fPIC -I/usr/include/python3.6 -shared -o spam.so
	
clean:
	rm *.so
