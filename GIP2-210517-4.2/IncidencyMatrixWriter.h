#pragma once

#include "Writer.h"

class IncidencyMatrixWriter : public Writer
{
public:	
	IncidencyMatrixWriter(Graph* g) : Writer{g} {
		getIncidencyMatrix();
	};
	std::string toString() const; 
private:
	std::vector<std::vector<float>> inzidenzMatrix;
	void getIncidencyMatrix();
};

