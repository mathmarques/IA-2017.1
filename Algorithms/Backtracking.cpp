#include "Backtracking.h"

string Backtracking::getName(){
	return "Backtracking";
}

void Backtracking::solve(){
	this->solution = this->backtraking(this->root);
}

State* Backtracking::backtraking(State* state){
	this->visited++;
	this->memoryStates[state->ruler] = state;

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

        if((child = this->backtraking(child)))
        	return child;
    }

    return nullptr;
}
