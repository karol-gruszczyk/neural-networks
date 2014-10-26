#ifndef NEURON_H
#define  NEURON_H

#include <vector>
#include <iostream>

#include "Connection.h"

class Connection;
class Neuron
{
public:
	Neuron();
	~Neuron();
	void feedForward();
	void updateInputWeights();

	double outputValue;
	double gradient;
	std::vector <Connection*> forwardConnections;
	std::vector <Connection*> backwardConnections;

	static double activationFunction(const double x);
	static double activationFunctionDerivative(const double x);
};

#endif
