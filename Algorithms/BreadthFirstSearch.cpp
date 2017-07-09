#include "BreadthFirstSearch.h"

string BreadthFirstSearch::getName(){
	return "Breadth-First Search";
}

void BreadthFirstSearch::solve(){
    queue<State*> q;
    State *state;
    State *child;

    q.push(this->root);
    this->memoryStates[this->root->ruler] = this->root;
    do {
        state = q.front();
        q.pop();

        this->visited++;

        if(state->isSolution()) {
            this->solution = state;
            return;
        }

        while((child = state->getNextChild())) {
            this->expanded++;
            if(!(this->memoryStates.count(child->ruler) > 0)){
                this->memoryStates[state->ruler] = state;
                q.push(child);
            } else
                delete child;
                
        }
    } while (!q.empty());
}
