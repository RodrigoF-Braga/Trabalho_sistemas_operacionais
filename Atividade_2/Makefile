# Makefile

CC = cc
CFLAGS = -Wall -Wextra -O2

all: criador_processos hello

criador_processos: criador_processos.c
	$(CC) $(CFLAGS) -o criador_processos criador_processos.c

hello: hello.c
	$(CC) $(CFLAGS) -o hello hello.c

clean:
	rm -f criador_processos hello
