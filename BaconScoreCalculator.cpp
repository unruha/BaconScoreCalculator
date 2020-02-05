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
			if (lineContents == "") continue;

			istringstream parseLine(lineContents);
			string name;
			string movieLine;
			vector<string> movies;

			getline(parseLine, name, '\t');

			while (getline(parseLine, movieLine))
			{
				if (movieLine.empty())
				{
					break;
				}
				string movie(movieLine.begin(), find(movieLine.begin(), movieLine.end(), '('));
				movies.push_back(movie);
			}

			theGraph.Add(name, movies);
		}
	}
	return true;
}

int main(int argc, const char* argv[])
{
	BaconScoreCalculator myCalculator;
	myCalculator.AddActors(argv[1]);

}
