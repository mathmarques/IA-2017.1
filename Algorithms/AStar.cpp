#include "AStar.h"

string AStar::getName(){
	return "A Star";
}

bool AStar::compare(State *a, State *b){
    return (a->cost + a->getHeuristicValue()) > (b->cost + b->getHeuristicValue());
}

void AStar::solve(){
	priority_queue<State*, vector<State*>, bool (*)(State*, State*)> pq(AStar::compare);
    State *state;
    State *child;

    pq.push(this->root);
    
    do {
        state = pq.top();
        pq.pop();

        this->visited++;
        visitedStates[state->ruler] = state;

        if(state->isSolution()) {
            this->solution = state;
            return;
        }

        while((child = state->getNextChild())) {
            this->expanded++;
            if(!(visitedStates.count(child->ruler) > 0))
                pq.push(child);
        }
    } while (!pq.empty());
}
