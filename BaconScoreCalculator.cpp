#include "BaconScoreCalculator.h"

//name: Adrian Unruh
//student id: 1978507

//default constructor
BaconScoreCalculator::BaconScoreCalculator()
{
}

//method: AddActors
//input: a string which is the filename to be read in
//output: fills up the actorsgraph with the actors and movies that are in the file
bool BaconScoreCalculator::AddActors(string fileName)
{
	//ifstream that gets the file with name fileName
	ifstream file(fileName);
	//a string that will hold each line as they are read in
	string lineContents;

	//determines if the file to be read in exists
	if (!file)
	{
		cout << "ERROR: Unable to open file" << endl;
		return false;
	}

	//continues looping until the end of the file is reached
	//retrieves the line of the file and puts it into string lineContents
	while (!file.eof())
	{
		while (getline(file, lineContents))
		{
			if (lineContents.empty())
			{
				break;
			}
			if (lineContents == "") continue;

			istringstream parseLine(lineContents);

			//holds the name to be stored in the graph
			string name;
			//holds the part of the line that includes the moviename (still needs to be parsed)
			string movieLine;
			vector<string> movies;

			getline(parseLine, name, '\t');
			cout << name << endl;

			string firstMovie;
			getline(parseLine, firstMovie, '(');

			//holds the first movie that is on the same line as the name of the actor
			firstMovie.erase(remove(firstMovie.begin(), firstMovie.end(), '\t'), firstMovie.end());
			movies.push_back(firstMovie);
			cout << '\t' << firstMovie << endl;
			
			//loops through each line that does not include the name of an actor
			while (getline(file, movieLine, '\n'))
			{
				parseLine.ignore();
				if (movieLine.length() == 0)
				{
					break;
				}
				//parses out the movie name from the movie line
				string movie(movieLine.begin(), find(movieLine.begin(), movieLine.end(), '('));
				//removes all extra tabs from the movie name that is about to be inserted into the graph
				movie.erase(remove(movie.begin(), movie.end(), '\t'), movie.end());
				//stores whether or not a duplicate movie was found
				bool found = false;
				for (int i = 0; i < movies.size(); i++)
				{
					if (movie == movies[i])
					{
						found = true;
					}
				}

				//if a duplicate was not found, then add the actor to the graph
				if (!found)
				{
					cout << '\t' << movie << endl;
					movies.push_back(movie);
				}
			}

			theGraph.Add(name, movies);
		}
	}
	return true;
}

//method: printActorsGraph (for testing purposes only)
//input: none
//output: prints out the names of the actors stored in the graph in order
void BaconScoreCalculator::printActorsGraph() const
{
	theGraph.printGraph();
}

//method: baconIndex
//input: none
//output: returns the location of actor 'Kevin Bacon' in the graph
int BaconScoreCalculator::baconIndex() const
{
	return theGraph.findBaconIndex();
}

//method: DijkstraAlgorithm
//input: the index of the actor to find the distances from
//output: performs the dijkstra algorithm on the contents of the graph and prints out 
//each actor and their bacon score
void BaconScoreCalculator::DijkstraAlgorithm(int index) const
{
	theGraph.BreadthFirstSearch(index);
}

//main method
int main(int argc, const char* argv[])
{
	BaconScoreCalculator myCalculator;
	myCalculator.AddActors(argv[1]);
	int index = myCalculator.baconIndex();
	myCalculator.DijkstraAlgorithm(index);
}
