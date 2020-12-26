CXX=g++
CXXFLAGS=-std=c++17 -Wall -Wextra -pedantic -g
LINK.o=$(LINK.cc)

all: main

main: main.o Car.o Reservation.o

clean:
	rm -f *.o main
