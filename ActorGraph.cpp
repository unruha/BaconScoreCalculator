#include "ActorGraph.h"

//name: Adrian Unruh
//student id: 1978507

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
		for (int j = 0; j < actorMovies[location].size(); j++)
		{
			if (movies[i] == actorMovies[location][j])
			{
				return true;
			}
		}
	}
	return false;
}

//method: findIndex
//input: a vector to be searched, a string which is the key
//outputs the location of the string that was passed into the vector
int ActorGraph::findIndex(vector<string> theVector, string theString) const
{
	for (int j = 0; j < theVector.size(); j++)
	{
		if (theVector[j] == theString)
		{
			return j;
		}
	}
}

//method: printGraph
//input: none
//output: each actor in the graph followed by all of the actors that they have a common movie with
void ActorGraph::printGraph() const
{
	for (int i = 0; i < actors.size(); i++)
	{
		for (int j = 0; j < actors[i].size(); j++)
		{
			cout << actors[i][j] << '\t';
		}
		cout << endl;
	}
}

//method: BreadthFirstSearch
//input: an integer that is the location of the actor to find the distances from
//output: performs BreadthFirstSearch on the graph and prints out the actors and their bacon scores
void ActorGraph::BreadthFirstSearch(int src) const
{
	//holds the location of the previous vertex
	vector<int> prev;
	//holds each of the actors as a string
	vector<string> nodes;
	//holds the current shortest distances between each actor and the actor to be searched
	vector<int> distances;

	for (int i = 0; i < actors.size(); i++)
	{
		distances.push_back(99999);
		nodes.push_back(actors[i][0]);
		prev.push_back(-1);
	}

	//the distance from the search actor to itself is always zero
	distances[src] = 0;
	set<int> s;
	//the queue which will hold each of the paths currently being searched
	list<int> queue;

	//add each node into the queue
	for (int i = 0; i < actors.size(); i++)
	{
		queue.push_back(i);
	}

	while (!queue.empty())
	{
		list<int>::iterator i;
		i = min_element(queue.begin(), queue.end());
		int u = *i; //the minimum element from the queue
		queue.remove(u);
		s.insert(u);

		//loops through all of the adjacent actors of the one currently in the queue
		for (int i = 1; i < actors[u].size(); i++)
		{
			//holds the index of the node whos path is going to be searched next
			int index = findIndex(nodes, actors[u][i]);
			
			if (distances[u] + 1 < distances[index])
			{
				distances[index] = distances[u] + 1;
				prev[index] = u;
			}
		}
	}

	//loops through all of the distances and prints them out alongside their corresponding actor name
	for (int i = 0; i < nodes.size(); i++)
	{
		cout << nodes[i] << '\t' << distances[i] << endl;
	}
}

//method: findBaconIndex
//input: none
//out: returns an integer that is the index of kevin bacon in the graph
int ActorGraph::findBaconIndex() const
{
	for (int i = 0; i < actors.size(); i++)
	{
		if (actors[i][0] == "Bacon, Kevin (I)")
		{
			return i;
		}
	}
	return -1;
}


