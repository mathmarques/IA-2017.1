#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

class State {
private:
	int heuristicValue;	
	bool heuristicCalculated;
	
public:
	int n;
	string ruler;
	int emptyPosition;

	int depth;
	int cost;

	State *parent;
	vector<State*> children;

	bool allChildrenFetched;
	int childIt;

	State(int n, string ruler, int emptyPosition);
	State(State* parent, int newEmptyPosition);
	~State();
	vector<State*> getChildren();
	State* getNextChild();
	int getHeuristicValue();
	stack<State*> getPath();
	bool isSolution();

};

#endif // STATE_H_INCLUDED
