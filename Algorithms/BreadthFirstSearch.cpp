#include "BreadthFirstSearch.h"

string BreadthFirstSearch::getName(){
	return "Breadth-First Search";
}

void BreadthFirstSearch::solve(){
    queue<State*> q;
    State *state;
    State *child;

    q.push(this->root);
    
    do {
        state = q.front();
        q.pop();

        this->visited++;
        visitedStates[state->ruler] = state;

        if(state->isSolution()) {
            this->solution = state;
            return;
        }

        while((child = state->getNextChild())) {
            this->expanded++;
            if(!(visitedStates.count(child->ruler) > 0))
                q.push(child);
            else
                delete child;
        }
    } while (!q.empty());
}
