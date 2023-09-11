run:
	gcc -o main.exe main.c
	./main.exe

build:
	gcc -o main.exe main.c

clean:
	rm -f main.exe