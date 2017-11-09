all: signals.c
	gcc -o signal signals.c
clean:
	rm *~
run: all
	./signal
