#ifndef LAYER_H
#define LAYER_H

#include <vector>

#include "Neuron.h"
#include "Connection.h"


using namespace std;

class Layer
{
public:
	Layer(unsigned neuronNum);
	~Layer();

	vector<Neuron*> neurons;
	Neuron biasNeuron;

	void createConnections(Layer &targetLayer, bool useBiasNeurons);
private:
};

#endif

