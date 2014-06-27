#include "SOM.h"

SOM::SOM(int size, int dimensionality)
{
	SIZE = size;
	DIMENSIONALITY = dimensionality;
	_learningRate = 1.f;
	_neighborhoodRadius = 0.f;
}

SOM::~SOM()
{
		
}

int SOM::getSize() const
{
	return SIZE;
}

int SOM::getDimensionality() const
{
	return DIMENSIONALITY;
}

void SOM::setLearningRate(float rate)
{
	_learningRate = rate;
}

void SOM::setNeighborhoodRadius(float radius)
{
	_neighborhoodRadius = radius;
}

float SOM::getLearningRate() const
{
	return _learningRate;
}

float SOM::getNeighborhoodRadius() const
{
	return _neighborhoodRadius;
}
