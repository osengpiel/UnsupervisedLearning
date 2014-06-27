#ifndef _SQUARESOM
#define _SQUARESOM

#include <math.h>
#include "SOM.h"

class SquareSOM : public SOM
{
public:
	SquareSOM(int width, int dimensionality);
	virtual ~SquareSOM();

	//Returns the codebookvector at position (x,y)
	virtual std::vector<float> getCodebookVector(int x, int y) const throw (SOM::RangeError);

	//Returns the codebookvector at the n'th position
	virtual std::vector<float> getCodebookVector(int n) const throw (SOM::RangeError);

	//Runs the SOM-Algorithm with an input vector
	virtual void processVector(const std::vector<float>& vector) throw (SOM::InputError);
	
	//Sets the codebook vector at the n'th position
	virtual void setCodebookVector(int n, std::vector<float> vector) 
			throw (SOM::RangeError,SOM::InputError);

	//Sets the codebook vector at the position (x,y)
	void setCodebookVector(int x, int y, std::vector<float> vector) 
			throw (SOM::RangeError,SOM::InputError);

	//Sets the maximal number of iterations
	void setMaxIteration(int iterations);

	//Returns the maximal number of iterations
	int getMaxIteration() const;

	//Sets the maximal number of epochs
	//If the number of epochs is positive, the iterations are interpreted as the
	//number of iterations per epoch and the algorithm stops after the number of
	//epochs.
	void setMaxEpoch(int epochs);

	//Returns the maximum number of epochs
	int getMaxEpoch() const;

	//Returns the number of the current epoch
	int  getCurrentIteration() const;

	//Returns the number of the current epoch
	int getCurrentEpoch() const;

	//Sets the current iteration
	void setCurrentIteration(int it);

	//Sets the current epoch
	void setCurrentEpoch(int ep);

private:
	std::vector<float> **_codebookArray;
	float getDistance(const std::vector<float>&,const std::vector<float>&)
		throw (SOM::InputError);
	int _maxIteration;
	int _currentIteration;
	int _maxEpoch;
	int _currentEpoch;
};

#endif
