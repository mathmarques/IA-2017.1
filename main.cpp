#include <iostream>
#include <cstring>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>

//Algorithms
#include "Algorithms/Backtracking.h"
#include "Algorithms/BreadthFirstSearch.h"
#include "Algorithms/OrderedSearch.h"
#include "Algorithms/GreedySearch.h"
#include "Algorithms/AStar.h"
#include "Algorithms/DepthFirstSearch.h"
#include "Algorithms/IterativeDAStar.h"

using namespace std;

Algorithm *algorithm;
bool debug = false;
string file;

static void usage()
{
    cout << "Usage:\n" <<
        "    ./PuzzleSolver [options] [Algorithm] [input_file_path] \n\n" <<
        "Options:\n" <<
        "    -?              Show this help\n" <<
        "    -debug          Debug Mode\n\n" <<
        "Algorithms:\n" <<
        "     BT             Backtracking\n" <<
        "     BFS            Breadth First Search\n" <<
        "     DFS            Depth First Search\n" <<
        "     OS             Ordered Search\n" <<
        "     GS             Greedy Search\n" <<
        "     AS             A Star\n" <<
        "     IDA            Iterative Deepening A Star\n\n";
}

static int processArgs(int argC, const char * argV[]) {
    if (argC < 3)
    {
        usage();
        return 1;
    }

    int argInd;

    for(argInd = 1; argInd < argC-1; argInd++) {
        
        if (argV[argInd][0] != '-')
            break;

        if (!strcmp(argV[argInd], "-?")) {
            usage();
            return 2;
        } else if (!strcmp(argV[argInd], "-debug")) {
            debug = true;
        }
    }
    
    if (argInd != argC - 2) {
        cout << "You must select an Algorithm and a File Path!!" << endl;
        usage();
        return 1;
    }

    if(!strcmp (argV[argInd], "BT")) {
        algorithm = new Backtracking();
    } else if(!strcmp (argV[argInd], "BFS")) {
        algorithm = new BreadthFirstSearch();
    } else if(!strcmp (argV[argInd], "DFS")) {
        algorithm = new DepthFirstSearch();
    } else if(!strcmp (argV[argInd], "OS")) {
        algorithm = new OrderedSearch();
    } else if(!strcmp (argV[argInd], "GS")) {
        algorithm = new GreedySearch();
    } else if(!strcmp (argV[argInd], "AS")) {
        algorithm = new AStar();
    } else if (!strcmp (argV[argInd], "IDA")) {
        algorithm = new IterativeDAStar();
    } else {
        cout << "Invalid Algorithm!!" << endl;
        usage();
        return 3; 
    }

    argInd++;
    file = argV[argInd];

    return 0;
}

int main(int argC, const char * argV[]) {
    cout << endl;

    //Processing args
    int process = processArgs(argC, argV);
    if(process != 0)
        return process;

    if(!algorithm->readFromFile(file)){
        cout << "Failed to read the file: " << file << endl;
        return 1;
    }

    if(debug) {
        algorithm->run();
        cout.precision(5);
        cout << algorithm->getName() << ";" 
        << algorithm->elapsedSeconds << ";" 
        << algorithm->expanded << ";" 
        << algorithm->visited << ";" 
        << fixed << algorithm->expanded / (double) algorithm->visited << ";"
        << algorithm->solution->depth << ";"
        << algorithm->solution->cost << endl;
    } else {
        //Run
        cout << "Solving using Algorithm: " << algorithm->getName() << " ..." << endl;
        algorithm->run();
        algorithm->printStatistics();
    }    

    return 0;
}
