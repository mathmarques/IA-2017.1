#include "OrderedSearch.h"

string OrderedSearch::getName(){
	return "Ordered Search";
}

bool OrderedSearch::compare(State *a, State *b){
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
            else
                delete child;
        }
    } while (!pq.empty());
}
