#ifndef ITERATIVEDASTAR_H_INCLUDED
#define ITERATIVEDASTAR_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Algorithm.h"
#include "../State.h"

using namespace std;

class IterativeDAStar: public Algorithm {
private:
	void solve();
public:
	string getName();
};

#endif // ITERATIVEDASTAR_H_INCLUDED
