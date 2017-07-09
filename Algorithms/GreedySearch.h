#ifndef GREEDYSEARCH_H_INCLUDED
#define GREEDYSEARCH_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#include "Algorithm.h"
#include "../State.h"

using namespace std;

class GreedySearch: public Algorithm {
private:
	void solve();
public:
	string getName();
	static bool compare(State *a, State *b);
};

#endif // GREEDYSEARCH_H_INCLUDED
