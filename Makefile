CC=g++
CFLAGS=-c -O2 -std=c++11 
LDFLAGS= -lm
SOURCES=main.cpp State.cpp Algorithms/Algorithm.cpp Algorithms/Backtracking.cpp Algorithms/BreadthFirstSearch.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=PuzzleSolver

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o Algorithms/*.o PuzzleSolver