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

        if(this->memoryStates.count(state->ruler) > 0){
            delete state;
            continue;
        }

        this->visited++;
        this->memoryStates[state->ruler] = state->getHeuristicValue();

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
