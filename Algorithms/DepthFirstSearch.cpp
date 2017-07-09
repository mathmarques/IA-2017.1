#include "DepthFirstSearch.h"

string DepthFirstSearch::getName(){
	return "Depth-First Search";
}

void DepthFirstSearch::solve(){
    stack<State*> s;
    State *state;
    State *child;

    s.push(this->root);
    this->memoryStates[this->root->ruler] = this->root;
    do {
        state = s.top();
        s.pop();

        this->visited++;

        if(state->isSolution()) {
            this->solution = state;
            return;
        }

        while((child = state->getNextChild())) {
            this->expanded++;
            if(this->memoryStates.count(child->ruler) > 0){
                delete child;  
            } else {
                this->memoryStates[child->ruler] = child;
                s.push(child);
            }
        }
    } while (!s.empty());
}
