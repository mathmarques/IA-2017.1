#include "AStar.h"

string AStar::getName(){
	return "A Star";
}

bool AStar::compare(State *a, State *b){
    return a->getF() > b->getF();
}

void AStar::solve(){
	priority_queue<State*, vector<State*>, bool (*)(State*, State*)> pq(AStar::compare);
    State *state;
    State *child;

    pq.push(this->root);
    
    do {
        state = pq.top();
        pq.pop();

        if(visitedStates.count(state->ruler) > 0){
            continue;
        }
        
        this->visited++;
        visitedStates[state->ruler] = state;

        if(state->isSolution()) {
            this->solution = state;
            return;
        }

        while((child = state->getNextChild())) {
            this->expanded++;
            pq.push(child);
        }
    } while (!pq.empty());
}
