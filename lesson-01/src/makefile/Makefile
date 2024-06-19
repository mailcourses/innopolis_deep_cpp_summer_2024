CC=g++
FLAGS=-std=c++20 -Wall -Wextra -pedantic

all: main

main: main.o lib1.o lib2.o
	$(CC) $(FLAGS) lib1.o lib2.o main.o -o main -lgtest -lpthread

main.o: main.cpp lib1.hpp lib2.hpp
	$(CC) $(FLAGS) -c main.cpp -lgtest -lpthread

lib1.o: lib1.cpp lib1.hpp
	$(CC) $(FLAGS) -c lib1.cpp

lib2.o: lib2.cpp lib2.hpp
	$(CC) $(FLAGS) -c lib2.cpp

test:
	./main

umpalumpa:
	rm -f *.o main
