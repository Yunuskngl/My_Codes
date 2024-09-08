all: movie_program

movie_program: movie_program.o
	gcc -o movie_program movie_program.o

movie_program.o: movie_program.c
	gcc -c movie_program.c

clean:
	rm -f movie_program movie_program.o
