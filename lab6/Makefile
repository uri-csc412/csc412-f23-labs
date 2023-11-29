# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++20 -g -O3
OBJECTS = main.o
PROGRAMS = main

# Targets and Dependencies
all: $(PROGRAMS)

remake: clean main run

main: main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: cleanlogs
	./main

clean: cleanlogs
	rm -f $(PROGRAMS) $(OBJECTS) 

cleanlogs:
	rm -rf logFolder
