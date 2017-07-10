#include "Backtracking.h"

string Backtracking::getName(){
	return "Backtracking";
}

void Backtracking::solve(){
	this->solution = this->backtracking(this->root);
}

State* Backtracking::backtracking(State* state){
	this->visited++;
	this->memoryStates[state->ruler] = state->cost;

    if(state->isSolution())
        return state;

    State *child;
    while ((child = state->getNextChild()))
    {
        this->expanded++;

        if(this->memoryStates.count(child->ruler) > 0){
            delete child;
        	continue;
        }

        if((child = this->backtracking(child)))
        	return child;
    }

    delete state;

    return nullptr;
}
