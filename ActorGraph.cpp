#include "ActorGraph.h"

ActorGraph::ActorGraph()
{
}

//method: Add
//input: a string for actors name and a list of their movies
//output: adds an entry to the graph and any edges that it shares with the actors already in the graph
void ActorGraph::Add(string name, vector<string>& movies)
{
	//inserting into the actor private member of graph
	//a new subvector to be inserted into the actor private member of the graph 
	vector<string> newActor;
	newActor.push_back(name);
	actors.push_back(newActor);

	//inserting into the actorMovies private member of graph
	actorMovies.push_back(movies);

	//loops through each item in actorMovies to examine the movies that each actor has acted in except for the last
	//location which is the new actor that we just added
	for (int i = 0; i < actorMovies.size() - 1; i++)
	{
		if (hasSameMovie(i, movies))
		{
			//inserts the new actor into the existing chain
			actors[i].push_back(name);
			//inserts the adjacent actors into the new chain at the last index of 'actors'
			actors[actors.size() - 1].push_back(actors[i][0]);
		}
	}
}

//method: hasSameMovie
//input: an integer that is the index of 'actorMovies' that we are comparing to the new actors movies vector to be inserted
	//a vector of the movies of the new actor to be inserted into the graph
//output: a boolean that is true if a common movie has been found and false if otherwise
bool ActorGraph::hasSameMovie(int location, const vector<string>& movies) const
{
	//loops through each value in the actor to be inserted's movies
	for (int i = 0; i < movies.size(); i++)
	{
		//loops through each value in actorMovies at the vector at the given location
		for (int j = 0; j < actorMovies[location].size(); i++)
		{
			if (movies[i] == actorMovies[location][j])
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	return 0;
}