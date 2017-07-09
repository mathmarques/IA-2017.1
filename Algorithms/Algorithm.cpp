#include "Algorithm.h"

bool Algorithm::readFromFile(string file){
	fstream arq;
	bool read = true;

    try{
        arq.open(file.c_str());
        if(arq.is_open()){
        	int n;
            string ruler;
            arq >> n >> ruler;

            size_t emptyPos = ruler.find('-');
			if (emptyPos != string::npos) {
				this->root = new State(n, ruler, emptyPos);
			} else
				read = false;
        } else 
            read = false;
    } catch (...) {
        read = false;
    }

    return read;
}

void Algorithm::run(){
    clock_t begin = clock();

    this->solve();

    clock_t end = clock();
    this->elapsedSeconds = double(end - begin) / CLOCKS_PER_SEC;  
}

void Algorithm::printStatistics(){
    cout << "Statistics:" << endl;
    cout.precision(5);
    cout << " - Elapsed time(seconds): " << fixed << this->elapsedSeconds << endl;
    cout << " - Expanded nodes: " << this->expanded << endl;
    cout << " - Visited nodes: " << this->visited << endl;
    cout << " - Average branching factor: " << "TO-DO" << endl;
    if(solution != nullptr) {
        cout << " - Solution depth: " << solution->depth << endl;
        cout << " - Solution cost: " << solution->cost << endl;
        cout << " - Solution path: " << endl;
        stack<State*> path = solution->getPath();
        while(!path.empty()){
            cout << "    " << path.top()->ruler << endl;
            path.pop();
        }
    } else {
        cout << " !! Couldn't find a solution !!" << endl;
    }
}
