main: ASet.o main.o
	g++ -o main main.o ASet.o

ASet.o: ASet.cpp ASet.h Set.h
	g++ -c ASet.cpp -o ASet.o -I.

main.o: main.cpp ASet.o
	g++ -c main.cpp -o main.o -I.
