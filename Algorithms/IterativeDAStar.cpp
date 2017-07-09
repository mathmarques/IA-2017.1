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
	State *child;
    this->memoryStates[this->root->ruler] = this->root;

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
            state = state->parent;
    	}

        while((child = state->getNextChild())) {
            this->expanded++;
            if(this->memoryStates.count(child->ruler) > 0){
                if(this->memoryStates[child->ruler]->getF() <= child->getF()) {
                    delete child;
                } else {
                    delete this->memoryStates[child->ruler];
                    this->memoryStates[child->ruler] = child;
                    break;
                }
            } else {
                this->memoryStates[child->ruler] = child;
                break;
            }
        }

    	if(child != nullptr) {
    		state = child;
    		this->visited++;
    	} else {
    		if(state == this->root) {
                oldThreshold = threshold;
                threshold = min;
                min = -1;
                state->reset();
                this->memoryStates.clear();
                this->memoryStates[this->root->ruler] = this->root;
            } else {
                state = state->parent;
            }
        }
    }

	return;
}
