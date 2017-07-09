#include "GreedySearch.h"

string GreedySearch::getName(){
	return "Greedy Search";
}

bool GreedySearch::compare(State *a, State *b){
    if(a->getHeuristicValue() == b->getHeuristicValue())
        return a->depth > b->depth;
    else
        return a->getHeuristicValue() > b->getHeuristicValue();
}

void GreedySearch::solve(){
	priority_queue<State*, vector<State*>, bool (*)(State*, State*)> pq(GreedySearch::compare);
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
