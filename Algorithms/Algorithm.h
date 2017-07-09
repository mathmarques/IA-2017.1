#ifndef ALGORITHM_H_INCLUDED
#define ALGORITHM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <unordered_map>
#include <ctime>

#include "../State.h"

using namespace std;

class Algorithm {
private:
	virtual void solve() = 0;
public:
	~Algorithm();
	
	State *root = nullptr;
	State *solution = nullptr;

	unordered_map<string, State*> memoryStates;

	long long int visited = 0;
	long long int expanded = 0;
	double elapsedSeconds = 0;

	bool readFromFile(string file);
	void run();
	void printStatistics();

	virtual string getName() = 0;
};

#endif // ALGORITHM_H_INCLUDED
