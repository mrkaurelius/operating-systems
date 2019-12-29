CC=gcc

all: fork-01 fork-02 pthread-01 mutex-01

fork-01: fork-01.c 
	$(CC) fork-01.c -o fork-01.exe

fork-02: fork-02.c 
	$(CC) fork-02.c -o fork-02.exe

pthread-01: pthread-01.c 
	$(CC) -lpthread pthread-01.c -o pthread-01.exe

mutex-01: mutex-01.c
	$(CC) -lpthread mutex-01.c -o mutex-01.exe

.PHONY: clean
clean: 
	rm -f *.exe

