#pragma once
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class ActorGraph
{
public:
	//default constructor
	ActorGraph();
	//method: Add
	//input: a string for actors name and a list of their movies
	//output: adds an entry to the graph and any edges that it shares with the actors already in the graph
	void Add(string name, vector<string>& movies);

	//method: hasSameMovie
	//input: an integer that is the index of 'actorMovies' that we are comparing to the new actors movies vector to be inserted
		//a vector of the movies of the new actor to be inserted into the graph
	//output: a boolean that is true if a common movie has been found and false if otherwise
	bool hasSameMovie(int location, const vector<string>& movies) const;

private:
	vector<vector<string>> actorMovies;
	vector<vector<string>> actors;
};

