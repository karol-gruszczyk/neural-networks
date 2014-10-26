#include "Layer.h"


Layer::Layer(unsigned neuronNum)
{
	for (unsigned i = 0; i < neuronNum; ++i)
		neurons.push_back(new Neuron());
	biasNeuron.outputValue = 1.0;
}

Layer::~Layer()
{
	for (auto &neuron : neurons)
		delete neuron;
}

void Layer::createConnections(Layer &targetLayer, bool useBiasNeurons)
{
	for (auto &neuron : neurons)
		for (auto &targetNeuron : targetLayer.neurons)
		{
			Connection* conn = new Connection(neuron, targetNeuron);
			neuron->forwardConnections.push_back(conn);
			targetNeuron->backwardConnections.push_back(conn);
		}

	if (useBiasNeurons)
		for (auto &targetNeuron : targetLayer.neurons)
		{
			Connection* conn = new Connection(&biasNeuron, targetNeuron);
			biasNeuron.forwardConnections.push_back(conn);
			targetNeuron->backwardConnections.push_back(conn);
		}
}
