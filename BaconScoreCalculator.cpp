#include "BaconScoreCalculator.h"

BaconScoreCalculator::BaconScoreCalculator()
{
}

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
			string name;
			string movieLine;
			vector<string> movies;

			getline(parseLine, name, '\t');
			cout << name << endl;

			string firstMovie;
			getline(parseLine, firstMovie, '(');
			firstMovie.erase(remove(firstMovie.begin(), firstMovie.end(), '\t'), firstMovie.end());
			movies.push_back(firstMovie);
			cout << '\t' << firstMovie << endl;
			
			while (getline(file, movieLine, '\n'))
			{
				parseLine.ignore();
				if (movieLine.length() == 0)
				{
					break;
				}
				string movie(movieLine.begin(), find(movieLine.begin(), movieLine.end(), '('));
				//removes all extra tabs from the movie name that is about to be inserted into the graph
				movie.erase(remove(movie.begin(), movie.end(), '\t'), movie.end());
				bool found = false;
				for (int i = 0; i < movies.size(); i++)
				{
					if (movie == movies[i])
					{
						found = true;
					}
				}

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

void BaconScoreCalculator::printActorsGraph() const
{
	theGraph.printGraph();
}

int main(int argc, const char* argv[])
{
	BaconScoreCalculator myCalculator;
	myCalculator.AddActors(argv[1]);
	myCalculator.printActorsGraph();
}
