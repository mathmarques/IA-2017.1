#ifndef BREADTHFIRSTSEARCH_H_INCLUDED
#define BREADTHFIRSTSEARCH_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#include "Algorithm.h"
#include "../State.h"

using namespace std;

class BreadthFirstSearch: public Algorithm {
private:
	void solve();
public:
	string getName();
};

#endif // BREADTHFIRSTSEARCH_INCLUDED
