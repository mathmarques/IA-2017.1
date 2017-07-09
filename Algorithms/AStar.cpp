#include "AStar.h"

string AStar::getName(){
	return "A Star";
}

bool AStar::compare(State *a, State *b){
    if(a->getF() == b->getF())
        return a->depth > b->depth;
    else
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

        if(this->memoryStates.count(state->ruler) > 0){
            delete state;
            continue;
        }

        this->visited++;
        this->memoryStates[state->ruler] = state;

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
