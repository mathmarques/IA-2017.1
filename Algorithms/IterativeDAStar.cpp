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
    this->memoryStates[this->root->ruler] = this->root->getF();

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

        while((child = state->getNextChild())) {
            this->expanded++;
            this->visited++;
            if(this->memoryStates.count(child->ruler) > 0 && this->memoryStates[child->ruler] <= child->getF()){
                delete child;
            } else {
                this->memoryStates[child->ruler] = child->getF();
                break;
            }
        }

    	if(child != nullptr) {
    		state = child;
    	} else {
    		if(state == this->root) {
                oldThreshold = threshold;
                threshold = min;
                min = -1;
                state->reset();
                this->memoryStates.clear();
                this->memoryStates[this->root->ruler] = this->root->getF();
            } else {
                parent = state->parent;
                delete state;
                state = parent;
            }
        }
    }

	return;
}
