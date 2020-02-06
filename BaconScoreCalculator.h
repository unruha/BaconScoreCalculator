#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
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

	//method: printActorsGraph
	//input: none
	//output: each of the actors in the graph with the actors that they share a movie with
	void printActorsGraph() const;

private:
	ActorGraph theGraph;
};

