#include "State.h"

State::State(int n, string ruler, int emptyPosition){
	this->n = n;
	this->ruler = ruler;
	this->emptyPosition = emptyPosition;
	this->depth = 0;
	this->cost = 0;
	this->heuristicCalculated = false;
	this->heuristicValue = 0;
	this->allChildrenFetched = false;
	this->childIt = 0;
	this->parent = nullptr;
}

State::State(State* parent, int newEmptyPosition){
	this->n = parent->n;
	this->heuristicCalculated = false;
	this->heuristicValue = 0;
	this->allChildrenFetched = false;
	this->childIt = 0;

	this->depth = parent->depth + 1;
	this->emptyPosition = newEmptyPosition;
	this->cost = parent->cost + abs(parent->emptyPosition - newEmptyPosition);
	this->ruler = parent->ruler;
	swap(this->ruler[parent->emptyPosition], this->ruler[newEmptyPosition]);

	this->parent = parent;
	if(State::fillChildren)
		parent->children.push_back(this);
}

State::~State(){
	for (vector<State*>::iterator it = this->children.begin() ; it != this->children.end(); ++it) {
     delete (*it);
   } 
   this->children.clear();
}

vector<State*> State::getChildren(){
	if(State::fillChildren){
		if(!this->allChildrenFetched) {
			State *fetch;
			while((fetch = this->getNextChild()))
        		continue;
		}

		return this->children;
	} else {
		int saveIt = this->childIt;

		vector<State*> children;
		this->childIt = 0;
		State *fetch;
		while((fetch = this->getNextChild()))
        	children.push_back(fetch);

        this->childIt = saveIt;
        this->allChildrenFetched = false;

        return children;
	}
}

State* State::getNextChild(){
	if(this->allChildrenFetched)
		return nullptr;

	this->childIt++;

	//Left side of empty
	int pos = this->emptyPosition - this->childIt;

	if(pos < 0 || pos < this->emptyPosition - this->n) {
		// Right side of empty
		pos = this->emptyPosition + ( this->childIt - min(this->emptyPosition, this->n) );

		if(pos >= this->ruler.size() || pos > this->emptyPosition + this->n) {
			this->allChildrenFetched = true;
			return nullptr;
		}
	}

	return new State(this, pos);
}

int State::getHeuristicValue(){
	if(heuristicCalculated)
		return this->heuristicValue;

	int itUntil = this->n;
	if(this->emptyPosition < this->n)
		itUntil++;

	int hValue = 0;
	for(int i = 0; i < itUntil; i++)
		if(this->ruler[i] == 'A')
			hValue++;

	this->heuristicCalculated = true;
	this->heuristicValue = hValue;
	
	return hValue;
}

int State::getF() {
	return this->getHeuristicValue() + this->cost;
}

bool State::isSolution(){
	if(heuristicCalculated)
		return this->heuristicValue == 0;

	bool isSol = true;

	int itUntil = this->n;
	if(this->emptyPosition < this->n)
		itUntil++;

	for(int i = 0; i < itUntil; i++)
		if(this->ruler[i] == 'A') {
			isSol = false;
			break;
		}

	return isSol;
}

stack<State*> State::getPath(){
	stack<State*> path;
	State* par;

	path.push(this);
	while(path.top()->parent) {
		path.push(path.top()->parent);
	}

	return path;
}
