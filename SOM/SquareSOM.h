#ifndef _SQUARESOM
#define _SQUARESOM

#include <math.h>
#include "SOM.h"

class SquareSOM : public SOM
{
public:
	SquareSOM(int width, int dimensionality);
	virtual ~SquareSOM();

	std::vector<float> getCodebookVector(int x, int y) const throw (SOM::RangeError);
	virtual std::vector<float> getCodebookVector(int number) const throw (SOM::RangeError);
	virtual void processVector(const std::vector<float>& vector) throw (SOM::InputError);
	virtual void setCodebookVector(int number, std::vector<float> vector) 
			throw (SOM::RangeError,SOM::InputError);
	void setCodebookVector(int x, int y, std::vector<float> vector) 
			throw (SOM::RangeError,SOM::InputError);
private:
	std::vector<float> **_codebookArray;
};

#endif
