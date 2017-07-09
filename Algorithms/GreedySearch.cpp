#include "GreedySearch.h"

string GreedySearch::getName(){
	return "Greedy Search";
}

bool GreedySearch::compare(State *a, State *b){
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
