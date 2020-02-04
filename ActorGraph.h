#pragma once
#include <string>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;


class ActorGraph
{
public:

	//default constructor
	ActorGraph();
	//Add method
	//input: a string containing the name of the actor, a list address of the movies that the actor has participated in
	//output: a boolean that determines whether or not the actor has been inserted into the list
	//returns false if the actor is already in the list
	void Add(string name, const vector<string>& movies);

private:

	//the structure of each of the nodes in the adacency matrix with an actorNode as the first node
	struct adjacentNode
	{
		//the name of the actor
		string name;
		//pointer to the next adjacency node in the chain
		adjacentNode* next;
	};

	//the structure of each of the actors that are inserted into the list
	struct actorNode
	{
		//the first and last name of the actor
		string name;
		//a list containing each of the movies or tv shows that the actor has participated in
		vector<string> movieNames;
		//a pointer pointing to the next node in the list
		//represents the vertices that are adjacent to the first node (vertex)
		adjacentNode* next;
	};

	//holds each of the actorNodes in the adjacency list with each one pointing to a linked list of each of 
	//the nodes that are adjacent to itself in the list
	vector<actorNode*> actorList;

	//sameMovie helper method
	//input: two nodes, the first one representing the node to be inserted into the graph, and the second one is the comparison
	//as to whether or not they should have an edge between them
	//output: returns a boolean that is true if the two actors have acted in the same movie, and false if they have not
	bool sameMovie(actorNode* actor1, actorNode* actor2) const;

};

