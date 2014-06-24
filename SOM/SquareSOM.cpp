#include "SquareSOM.h"

SquareSOM::SquareSOM(int width, int dimensionality) :
	SOM(pow(width,2),dimensionality)
{
	std::vector<float> temp;
	for(int i = 0; i < SOM::getDimensionality(); i++)
	{
		temp.push_back(0.f);
	}
	_codebookArray = new std::vector<float>*[dimensionality];
	for(int i = 0; i < width; i++)
	{
		_codebookArray[i] = new std::vector<float>[dimensionality];
		for(int j = 0; j < width; j++)
		{
			_codebookArray[i][j] = temp;	
		}
	}
}

SquareSOM::~SquareSOM()
{
	for(int i = 0; i < SOM::getDimensionality(); i++)
	{
		delete _codebookArray[i];
	}
	delete _codebookArray;
}

std::vector<float> SquareSOM::getCodebookVector(int x, int y) const
	throw (SOM::RangeError)
{
	return getCodebookVector(x*SOM::getDimensionality()+y);
}

std::vector<float> SquareSOM::getCodebookVector(int number) const
	throw (SOM::RangeError)
{
	return _codebookArray[number % SOM::getDimensionality()][number /
		SOM::getDimensionality()];
}

void SquareSOM::processVector(const std::vector<float>& vector)
	throw (SOM::InputError)
{
	// Stuff to be done
}

void SquareSOM::setCodebookVector(int x, int y, std::vector<float> vector)
	throw (SOM::RangeError,SOM::InputError)
{
	setCodebookVector(x * SOM::getDimensionality() + y, vector);
}
void SquareSOM::setCodebookVector(int number, std::vector<float> vector)
	throw (SOM::RangeError,SOM::InputError)
{
	_codebookArray[number % SOM::getDimensionality()][number /
	SOM::getDimensionality()] = vector;
}
