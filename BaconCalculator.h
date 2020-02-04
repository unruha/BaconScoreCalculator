#pragma once
#include <string>
#include <iostream>
#include "ActorGraph.h"
using namespace std;

class BaconCalculator
{
public:

	//default constructor
	BaconCalculator();
	//AddActors
	//input: a text file that contains the names of the actors and the movies they participated in
	//output: a boolean indicating whether or not the text file was found and inserted into graph
	//inserts the actors names and movies into the private ActorGraph data member
	bool AddActors(string filename);
	//PrintActors
	//input: none
	//output: the names and bacon scores of each of the actors in the graph
	void PrintActors() const;

private:

	ActorGraph actors;

};

