CC=g++
CFLAGS=-c -O3 -std=c++11 -m64
LDFLAGS= -lm -m64
SOURCES=main.cpp State.cpp Algorithms/Algorithm.cpp Algorithms/Backtracking.cpp Algorithms/BreadthFirstSearch.cpp Algorithms/OrderedSearch.cpp Algorithms/DepthFirstSearch.cpp Algorithms/AStar.cpp Algorithms/GreedySearch.cpp Algorithms/IterativeDAstar.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=PuzzleSolver

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o Algorithms/*.o PuzzleSolver