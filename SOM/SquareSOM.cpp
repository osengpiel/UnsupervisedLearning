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
	if((int)vector.size() != getDimensionality())
	{
		throw InputError();
	}
	std::vector<float>* winner = nullptr;
	int winnerpos[2] = {0,0};

	for(int i = 0; i < getDimensionality(); i++)
	{
		for(int j = 0; j < getDimensionality(); j++)
		{
			if(!winner)
			{
				winner = &_codebookArray[i][j];
				winnerpos[0] = i;
				winnerpos[1] = j;
			}
			else if(getDistance(*winner,vector) >
				getDistance(_codebookArray[i][j],vector))
			{
				winner = &_codebookArray[i][j];
				winnerpos[0] = i;
				winnerpos[1] = j;
			}
		}
		float percentageOfProcess;
		if(getMaxEpoch() > 0)
		{
			percentageOfProcess = (float) getCurrentEpoch() /
				(getMaxEpoch()-1);
		}
		else
		{
			percentageOfProcess = (float) getCurrentIteration() /
				(getMaxIteration()-1);
		}

		float alpha = (1 - percentageOfProcess * SOM::getLearningRate());
		float sigma = (1 - percentageOfProcess *
			SOM::getNeighborhoodRadius());

		for(int i = 0; i < getDimensionality(); i++)
		{
			for(int j = 0; j < getDimensionality(); j++)
			{
				float h = alpha * exp(-1 * (pow(winnerpos[0] - i,2)
					+ pow(winnerpos[1] - j,2)) / (2 * pow(sigma,2)));

				std::vector<float> temp;
				for(int k = 0; k < getDimensionality(); k++)
				{
					_codebookArray[i][j][k] += 
						h * (vector[k] - _codebookArray[i][j][k]);
				}
			}
		}
		
		setCurrentIteration(getCurrentIteration()+1);
		if(getMaxEpoch() > 0)
		{
			if(getCurrentIteration() >= getMaxIteration())
			{
				setCurrentIteration(0);
				setCurrentEpoch(getCurrentEpoch()+1);
			}
		}
	}

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

float SquareSOM::getDistance(const std::vector<float>& vec1,const std::vector<float>& vec2)
	throw (SOM::InputError)
{
	if(vec1.size() != vec2.size())
	{
		throw SOM::InputError();
	}
	float temp = 0;
	for(unsigned int i = 0; i < vec1.size(); i++)
	{
		temp += pow(vec1[i]+vec2[i],2);
	}
	temp = sqrt(temp);
	
	return temp;
}

void SquareSOM::setMaxIteration(int iterations)
{
	_maxIteration = iterations;
}

void SquareSOM::setMaxEpoch(int epochs)
{
	_maxEpoch = epochs;
}

void SquareSOM::setCurrentIteration(int iteration)
{
	_currentIteration = iteration;
}

void SquareSOM::setCurrentEpoch(int epoch)
{
	_currentEpoch = epoch;
}

int SquareSOM::getMaxIteration() const
{
	return _maxIteration;
}

int SquareSOM::getMaxEpoch() const
{
	return _maxEpoch;
}

int SquareSOM::getCurrentIteration() const
{
	return _currentIteration;
}

int SquareSOM::getCurrentEpoch() const
{
	return _currentEpoch;
}
