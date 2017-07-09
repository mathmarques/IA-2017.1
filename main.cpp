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
        "     back           Backtracking\n" <<
        "     bfs            Breadth First Search\n\n";
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

    if(!strcmp (argV[argInd], "back")) {
        algorithm = new Backtracking();
    } else if(!strcmp (argV[argInd], "bfs")) {
        algorithm = new BreadthFirstSearch();
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

    //Run
    cout << "Solving using Algorithm: " << algorithm->getName() << " ..." << endl;
    if(!algorithm->readFromFile(file)){
        cout << "Failed to read the file: " << file << endl;
        return 1;
    }

    algorithm->run();
    algorithm->printStatistics();

    return 0;
}
