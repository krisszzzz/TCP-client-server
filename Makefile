tcp: tcp.c tcp.h main.c
	gcc -o tcp tcp.c main.c

clean:
	rm tcp
