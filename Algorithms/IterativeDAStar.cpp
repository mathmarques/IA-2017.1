#include "IterativeDAStar.h"

string IterativeDAStar::getName(){
	return "Iterative Deepening A Star";
}

void IterativeDAStar::solve(){
	int threshold = this->root->getF();
	int oldThreshold = -1;
	int min = -1;

	this->visited++;
	State *state = this->root;
	State *child, *parent;
	while(true){
		if(threshold == oldThreshold) //Fail to found solution
    		break;

    	if(state->isSolution() && state->getF() <= threshold) { //Solution found
    		this->solution = state;
    		break;
    	}

    	if(state->getF() > threshold) {
    		if(state->getF() < min || min == -1)
    			min = state->getF();
            parent = state->parent;
    		delete state;
            state = parent;
    	}

    	if((child = state->getNextChild())) {
    		state = child;
    		this->visited++;
    		this->expanded++;
    	} else {
    		if(state == this->root) {
                oldThreshold = threshold;
                threshold = min;
                min = -1;
                state->reset();
            } else {
                parent = state->parent;
                delete state;
                state = parent;
            }
        }
    }

	return;
}
