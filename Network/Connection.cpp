#include "Connection.h"


Connection::Connection(Neuron* startNeuron, Neuron* endNeuron)
{
	this->startNeuron = startNeuron;
	this->endNeuron = endNeuron;
	weight = Connection::getRandomWeight();
	deltaWeight = 0.0;
	std::cout << "made a connection!" << std::endl;
}


Connection::~Connection()
{
	std::cout << "destroyed a connection" << std::endl;
}

double Connection::getRandomWeight()
{
	return rand() / double(RAND_MAX);
}

