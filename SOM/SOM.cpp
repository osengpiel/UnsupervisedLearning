#include "SOM.h"

SOM::SOM(int size, int dimensionality)
{
	SIZE = size;
	DIMENSIONALITY = dimensionality;
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
