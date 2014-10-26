#include "Neuron.h"

Neuron::Neuron()
{
	std::cout << "made a neuron!" << std::endl;
}


Neuron::~Neuron()
{
	for (auto &conn : backwardConnections)
		delete conn;
	std::cout << "destroyed a neuron!" << std::endl;
}

void Neuron::feedForward()
{
	double sum = 0.0;
	for (auto &conn : backwardConnections)
		sum += conn->startNeuron->outputValue * conn->weight;

	outputValue = Neuron::activationFunction(sum);
}

double Neuron::activationFunction(const double x)
{
	// it needs to return a value in between [-1.0..1.0]
	return tanh(x);
}

double Neuron::activationFunctionDerivative(const double x)
{
	double tanh_x = x;// tanh(x);
	return 1.0 - tanh_x * tanh_x;
}
