#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "ActorGraph.h"
using namespace std;

class BaconScoreCalculator
{
public:
	//default constructor
	BaconScoreCalculator();
	//method: AddActors
		//this method reads in actors and their movies and adds them to the underlying graph data structure
	//input: a string which is the file name to be read
	//output: a boolean which returns true if the actors in the file were successfully added to the graph
	bool AddActors(string fileName);

private:
	ActorGraph theGraph;
};

