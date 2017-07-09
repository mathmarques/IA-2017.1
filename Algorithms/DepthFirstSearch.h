#ifndef DEPTHFIRSTSEARCH_H_INCLUDED
#define DEPTHFIRSTSEARCH_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#include "Algorithm.h"
#include "../State.h"

using namespace std;

class DepthFirstSearch: public Algorithm {
private:
	void solve();
public:
	string getName();
};

#endif // DEPTHFIRSTSEARCH_H_INCLUDED
