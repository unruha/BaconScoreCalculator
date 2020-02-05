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
	while (!file.eof())
	{
		//retrieves the line of the file and puts it into string lineContents
		getline(file, lineContents);
		if (lineContents.empty())
		{
			break;
		}
		//holds part of lineContents
		istringstream parseLine(lineContents);
		//holds the name of the actor parsed from lineContents
		string name;
		//holds the movies that the actor has participated in according to the file contents
		vector<string> movies;
		if (lineContents[0] != '\t')
		{
			//stores the part of the string up until the first tab into the name variable
			getline(parseLine, name, '\t');
			string firstMovie;
			//stores the first movie that is on the same line as the actor name
			getline(parseLine, firstMovie, '(');
			movies.push_back(firstMovie);
			parseLine.ignore();
			//begin storing all the movies that are not on the same line as the actor names
			string movieLine;
			while (getline(parseLine, movieLine, '('))
			{

			}
		}
	}
}
