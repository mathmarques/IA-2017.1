#ifndef ASTAR_H_INCLUDED
#define ASTAR_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#include "Algorithm.h"
#include "../State.h"

using namespace std;

class AStar: public Algorithm {
private:
	void solve();
public:
	string getName();
	static bool compare(State *a, State *b);
};

#endif // ASTAR_H_INCLUDED
