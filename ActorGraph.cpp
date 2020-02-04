#include "ActorGraph.h"

ActorGraph::ActorGraph()
{
}

void ActorGraph::Add(string name, const vector<string>& movies)
{
	//pointer that points to new node to be inserted into the graph
	actorNode* insNode = new actorNode;
	insNode->name = name;
	insNode->movieNames = movies;
	insNode->next = nullptr;
	actorList.push_back(insNode);

	//loops through each actor in the actorlist except for the last one because that is the one that was just inserted
	for (int i = 0; i < actorList.size() - 1; i++)
	{
		//checks if the two actors contain a movie that is the same
		if (sameMovie(insNode, actorList[i]))
		{
			//a new adjacent node to insert into the chain that is adjacent to insNode
			adjacentNode* adjacent = new adjacentNode;
			adjacent->name = insNode->name;
			adjacent->next = nullptr;

			//a new adjacent node to insert into the chain of insNode
			adjacentNode* insAdjacent = new adjacentNode;
			insAdjacent->name = actorList[i]->name;
			insAdjacent->next = nullptr;

			//temporary node pointer to find the end of the chain
			adjacentNode* curr = actorList[i]->next;

			//determines if the first node in the chain does not exist
			if (curr == nullptr)
			{
				actorList[i]->next = adjacent;
			}
			else
			{
				curr = actorList[i]->next;
				
				//loops until one node before the end of the chain
				while (curr->next != nullptr)
				{
					curr = curr->next;
				}
				//puts the new node on the end of the chain
				curr->next = adjacent;
			}

			//pointer to the first node in the new node chain that was added
			//it is located at actorList.size() - 1 because push_back always puts the item at the end of the vector
			adjacentNode* temp = actorList[actorList.size() - 1]->next;
			if (curr == nullptr)
			{
				//puts insAdjacent onto the end of the new chain that was inserted
				actorList[actorList.size() - 1]->next = insAdjacent;
			}
			else
			{
				//loops to the end of the new chain and inserts the node
				while (temp->next != nullptr)
				{
					temp = temp->next;
				}
				temp->next = insAdjacent;
			}
		}
	}
}

bool ActorGraph::sameMovie(actorNode* actor1, actorNode* actor2) const
{
	//loops through each movie in the first actor node
	for (int i = 0; i < actor1->movieNames.size(); i++)
	{
		//searches the movie names of actor 2 and determines if the movie at 'i' of actor 1 is present in the movie list of actor 2
		if (find(actor2->movieNames.begin(), actor2->movieNames.end(), actor1->movieNames[i]) != actor2->movieNames.end())
		{
			return true;
		}
	}
	return false;
}
