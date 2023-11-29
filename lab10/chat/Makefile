# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -pthread -std=c++2a -g -O3
OBJECTS = main.o
PROGRAMS = main

# Targets and Dependencies
all: $(PROGRAMS)

remake: clean main run

main: main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run:
	./main

clean: 
	rm -f $(PROGRAMS) $(OBJECTS) 
