#ifndef CONNECTION_H
#define CONNECTION_H

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Neuron.h"

class Neuron;
class Connection
{
public:
	Connection(Neuron* startNeuron, Neuron* endNeuron);
	~Connection();
	Neuron* startNeuron;
	Neuron* endNeuron;
	double weight;
	double deltaWeight;
private:


	static double getRandomWeight();
};

#endif
