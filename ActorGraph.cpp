#include "ActorGraph.h"

bool ActorGraph::Add(string name, const vector<string>& movies)
{
	//pointer that points to new node to be inserted into the graph
	actorNode* insNode = new actorNode;
	insNode->name = name;
	insNode->movieNames = movies;
	actorList.push_back(insNode);
}

bool ActorGraph::sameMovie(actorNode& actor1, actorNode& actor2) const
{
	for (int i = 0; i < actor1.movieNames.size(); i++)
	{
		for (int j = 0; j < actor2.movieNames.size(); j++)
		{
			if (actor1.movieNames[i] == actor2.movieNames[j])
			{
				return true;
			}
		}
	}
	return false;
}
