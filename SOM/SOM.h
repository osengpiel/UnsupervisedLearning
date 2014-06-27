#ifndef _SOM
#define _SOM

#include<vector>

class SOM
{
public:
	class RangeError { };
	class InputError { };

	SOM(int size,int dimensionality);
	virtual ~SOM();

	int getSize() const;
	int getDimensionality() const;

	virtual std::vector<float> getCodebookVector(int number) const throw (RangeError) = 0;
	virtual void processVector(const std::vector<float>& vector) throw (InputError) = 0;
	virtual void setCodebookVector(int number, std::vector<float> vector) 
			throw (RangeError,InputError) = 0;

	void setLearningRate(float rate);
	void setNeighborhoodRadius(float radius);
	float getLearningRate() const;
	float getNeighborhoodRadius() const;
private:
	int SIZE;
	int DIMENSIONALITY;
	float _learningRate;
	float _neighborhoodRadius;

protected:
	void setSize(int size);
	void setDimensionality(int dimension);
};

#endif
