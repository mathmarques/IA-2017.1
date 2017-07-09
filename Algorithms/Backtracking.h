#ifndef BACKTRACKING_H_INCLUDED
#define BACKTRACKING_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Algorithm.h"
#include "../State.h"

using namespace std;

class Backtracking: public Algorithm {
private:
	void solve();
	State* backtraking(State* state);
public:
	string getName();
};

#endif // BACKTRACKING_H_INCLUDED
