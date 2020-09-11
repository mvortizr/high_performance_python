CC = gcc

default: pyexamples

pyexamples: hello.c
	$(CC) hello.c -fPIC -I/usr/include/python3.6 -shared -o hello.so
	
clean:
	rm *.so
