
CC=g++
FLAGS=-std=c++2b -Wall -Wextra

all: main

main: main.o utils.o
	$(CC) $(FLAGS) main.o utils.o -o main

main.o: main.cpp utils.hpp
	$(CC) $(FLAGS) main.cpp -c

utils.o: utils.hpp utils.cpp
	$(CC) $(FLAGS) utils.cpp -c

clean:
	rm -f *.o main

open_pdf:
	open ./lesson-09.pdf
