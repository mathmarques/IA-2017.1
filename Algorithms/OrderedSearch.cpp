#include "OrderedSearch.h"

string OrderedSearch::getName(){
	return "Ordered Search";
}

bool OrderedSearch::compare(State *a, State *b){
    if(a->cost == b->cost)
        return a->depth > b->depth;
    else
        return a->cost > b->cost;
}

void OrderedSearch::solve(){
	priority_queue<State*, vector<State*>, bool (*)(State*, State*)> pq(OrderedSearch::compare);
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
        this->memoryStates[state->ruler] = state->cost;

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
